#include "../icl/proto.h"

char	*open_read(char *file)
{
        char	buf[BUFSIZ] = {0};
        char	*bufp = NULL;
        int		r; 
        int		fd;

        fd = open(file, O_RDONLY);
        if (fd == -1)
                return (NULL);
        r = read(fd, buf, BUFSIZ);
        if (r <= 0)
                return (NULL);
        bufp = ft_strdup(buf);
        return (bufp);
}

void    print_arr(char **arr) 
{
        int check = 0;
        int len = 0;

        for (int y = 0; arr[y] != NULL; y++) {
                len = ft_strlen(arr[y]);
                for (int x = 0; x < len; x++) {
                        if (y % 2 == 0) {
                                if (x >= 2)
                                        printf("%c", arr[y][x]);
                                if (x + 1 >= len)
                                        check = 1;
                                if (arr[y][0] == '0' && check == 1)
                                        printf(" -   ");
                                if (arr[y][0] == '1' && check == 1)
                                        printf(" -   ");
                                if (arr[y][0] == '2' && check == 1)
                                        printf(" -   ");
                        } else
                                printf("%c", arr[y][x]);
                } 
                if (y % 2 != 0)
                        printf("\n");
                check = 0; 
                free(arr[y]);
        }
}

int main(int ac, char **av)
{
        char    **arr;
        char    *buf;

        if (ac > 4)
                return 1;
        if (ac <= 2) {
                if (ac == 2)
                        buf = open_read(av[1]);
                else
                        buf = open_read("./res/task.txt");
                if (buf == NULL)
                        write(2, "Not a file !\n", 13);
                else
                        arr = str_to_tab(buf, "\n:");
                print_arr(arr);
                free(buf);
                return (0);
        }
        buf = open_read("./res/task.txt");
        if (!is_option(ac, av, buf) && ac > 2) {
                write(2, "Wrong option !\n", 14);
                return 1;
        }
        free(buf);
        return (0);
}
