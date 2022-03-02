#include "../icl/icl.h"

bool    is_charset(char c, char *str)
{
        int i;

        i = 0;
        while (str[i] != '\0') {
                if (c == str[i])
                        return (true);
                i++;
        }
        return (false);
}

int	count_rows(char *str, char *charset)
{
        int	i;
        int	rows;

        rows = 0;
        i = 0;
        while (str[i] != '\0') {
                if (is_charset(str[i], charset))
                        rows++;
                i++;
        }
        return (rows);
}

int	*count_cols(char *str, char *charset)
{
        int	i;
        int	y;
        int u;
        int	rows;
        int *cols;

        i = 0;
        y = 0;
        u = 0;
        rows = count_rows(str, charset);
        if (rows == 0)
                return (0);
        cols = malloc(sizeof(int) * rows);
        if (cols == 0)
                return (0);
        while (i < rows) {
                if (is_charset(str[u], charset)) {
                        cols[i] = y;
                        i++;
                        y = -1;
                } 
                y++;
                u++;
        }
        return (cols);
}

char	**str_to_tab(char *str, char *charset)
{
        int		x;
        int		y;
        int		i;
        int		rows;
        int		*cols;
        char	**tab;

        i = 0;
        x = 0;
        y = 0;
        rows = count_rows(str, charset);
        cols = count_cols(str, charset);
        if (cols == 0 || rows == 0)
                return (NULL);
        tab = NULL;
        tab = malloc(sizeof(char *) * rows + 1);
        if (tab == NULL)
                return (NULL);
        while (y < rows) {
                tab[y] = malloc(sizeof(char) * cols[y] + 1);
                if (tab[y] == NULL)
                        return (NULL);
                while (x < cols[y]) {
                        if (!is_charset(str[i], charset)) {
                                tab[y][x] = str[i];
                                x++;
                        }
                        i++;
                }
                tab[y][x] = '\0';
                x = 0;
                y++;
        }
        tab[y] = NULL;
        return (tab);
}
