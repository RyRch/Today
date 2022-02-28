#include "../icl/icl.h"

int	ft_strlen(char *str) 
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (new == NULL)
		return (NULL);
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*open_read(char *file)
{
	char	buf[BUFSIZ];
	char	*bufp;
	int		r; 
	int		fd;

    bufp = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	r = read(fd, buf, BUFSIZ);
	bufp = ft_strdup(buf);
	if (r <= 0)
		return (NULL);
	return (bufp);
}

int main(int ac, char **av)
{
        char    **tab; 
        char    *buf;
        //t_s     p;

        if (ac != 2)
                return (1);
        //p.buf = NULL;
        buf = NULL;
        buf = ft_strdup(open_read(av[1]));
        tab = str_to_tab(buf, "\n:");
        for (int i = 0; i < count_rows(buf, "\n:"); i++)
                printf("tab[%d] = %s\n", i, tab[i]);
        return (0);
}
