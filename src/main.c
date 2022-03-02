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

void    print_arr(char **arr) 
{
        for (int i = 0; arr[i] != NULL; i++) {
                printf("arr[%d] = %s\n", i, arr[i]);
        }
}

int main(int ac, char **av)
{
        char    **arr;
        char    *buf;
        //t_s     p;

        if (ac > 4)
                return 1;
        if (ac <= 2) {
                arr = NULL;
                buf = NULL;
                if (ac == 2)
                        buf = ft_strdup(open_read(av[1]));
                else
                        buf = ft_strdup(open_read("./res/task.txt"));
                if (buf == NULL)
                        write(2, "Not a file !\n", 13);
                else
                        arr = str_to_tab(buf, "\n:");
                print_arr(arr);
        }
        buf = NULL;
        buf = ft_strdup(open_read("./res/task.txt"));
        if (!is_option(ac, av, buf) && ac > 2) {
                write(2, "Wrong option !\n", 14);
                return 1;
        }
        free(buf);
        return (0);
}
