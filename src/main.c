#include "../icl/proto.h"
#include <stdio.h>

char	*get_file(char *file)
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

void    fill_struct(s_t *s)
{
        s->buf = NULL;
        s->file = NULL;
        s->file = malloc(sizeof(char) * 1000);
        ft_strcpy(s->file, getenv("HOME"));
        ft_strcat(s->file, "/");
        ft_strcat(s->file, ".today");
        s->buf = get_file(s->file);
        s->arr = NULL;
        s->arr = str_to_tab((char *)s->buf, ":\n");
}

int main(int ac, char **av)
{
        p_s     *head = NULL;
        s_t     s;

        fill_struct(&s);
        if (ac == 1) {
                if (s.buf == NULL)
                        write(2, "Not a file !\n", 13);
                else
                        print_arr(s.arr);
                free((char *)s.buf);
                return (0);
        }
        head = str_to_list(s.arr);
        if (!is_option(ac, av, &head) && ac > 2) {
                write(2, "Wrong option !\n", 14);
                return 1;
        }
        free((char *)s.buf);
        return (0);
}
