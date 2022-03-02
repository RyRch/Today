#include "../icl/icl.h"

void    begin_opt(char *file, char *id)
{
        char    **arr;
        char    charset[3];

        arr = NULL;
        ft_strcpy(charset, "\n:");
        arr = str_to_tab(file, charset);
        for (int y = 0; y < count_rows(file, charset); y++) {
                if (y % 2 == 0 && arr[y][2] == id[0])
                        arr[y][0] = '1';
        }
        print_arr(arr);
}

void    check_opt(char *file, char *id)
{
        char    **arr;
        char    charset[3];

        arr = NULL;
        ft_strcpy(charset, "\n:");
        arr = str_to_tab(file, "\n:");
        for (int y = 0; y < count_rows(file, charset); y++) {
                if (y % 2 == 0 && arr[y][2] == id[0])
                        arr[y][0] = '2';
        }
        print_arr(arr);
}

void    edit_opt(char *file, char *id, char *new)
{
        char    **arr;
        char    charset[3];

        arr = NULL;
        ft_strcpy(charset, "\n:");
        arr = str_to_tab(file, "\n:");
        for (int y = 0; y < count_rows(file, charset); y++) {
                if (y % 2 == 0 && arr[y][2] == id[0])
                        arr[y + 1] = ft_strdup(new);
        }
        print_arr(arr);
}

bool    is_option(int ac, char **av, char *buf)
{
        if (ac == 3 && ft_strcmp(av[1], "-a")) {
                //                    add_opt();
                return true;
        }
        if (ac == 3 && ft_strcmp(av[1], "-b") && is_num(av[2])) {
                begin_opt(buf, av[2]);
                return true;
        }
        if (ac == 3 && ft_strcmp(av[1], "-c") && is_num(av[2])) {
                check_opt(buf, av[2]);
                return true;
        }
        if (ac == 3 && ft_strcmp(av[1], "-d") && is_num(av[2])) {
                //                       del_opt();
                return true;
        }
        if (ac == 4 && ft_strcmp(av[1], "-e") && is_num(av[2])) {
                edit_opt(buf, av[2], av[3]);
                return true;
        }
        return false;
}
