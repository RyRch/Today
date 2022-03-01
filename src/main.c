#include "../icl/icl.h"

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

void    print_arr(t_s *p, char *buf)    
{
        for (int i = 0; i < count_rows(buf, "\n:"); i++)
                printf("arr[%d] = %s\n", i, p->arr[i]);
}

int main(int ac, char **av)
{
        char    *buf;
        t_s     p;

        if (!is_option(ac, av)) {
                write(2, "Wrong option !\n", 14);
                return 1;
        }
        buf = NULL;
        buf = ft_strdup(open_read(av[1]));
        if (buf == NULL)
                write(2, "Not a file !\n", 13);
        else
                p.arr = str_to_tab(buf, "\n:");
        if (ac == 2)
                print_arr(&p, buf);
        return (0);
}
