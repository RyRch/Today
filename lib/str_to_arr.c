#include "../icl/icl.h"

bool    is_charset(char c, char *str)
{
        for (int i = 0; str[i] != '\0'; i++) {
                if (c == str[i])
                        return (true);
        }
        return (false);
}

int	count_rows(char *str, char *charset)
{
        int	i = 0;
        int	rows = 0;

        while (str[i] != '\0') {
                if (is_charset(str[i], charset))
                        rows++;
                i++;
        }
        return (rows);
}

int	*count_cols(char *str, char *charset)
{
        int	i = 0;
        int	y = 0;
        int u = 0;
        int	rows;
        int *cols;

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
        int		x = 0;
        int		y = 0;
        int		i = 0;
        int		rows;
        int		*cols;
        char	**tab;

        rows = count_rows(str, charset);
        cols = count_cols(str, charset);
        if (cols == 0 || rows == 0)
                return (NULL);
        tab = malloc(sizeof(*tab) * (rows + 1));
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
        free(cols);
        return (tab);
}
