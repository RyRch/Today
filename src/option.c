#include "../icl/proto.h"

void    begin_opt(char *file, char *id)
{
        char    **arr = NULL;
        char    *str = NULL;
        char    charset[3];
        int     fd = 0;

        ft_strcpy(charset, "\n:");
        arr = str_to_tab(file, charset);
        for (int y = 0; y < count_rows(file, charset); y++) {
                if (y % 2 == 0 && arr[y][2] == id[0])
                        arr[y][0] = '1';
        }
        str = tab_to_str(arr);
        free(*arr);
        fd = open("./res/task.txt", O_WRONLY);
        write(fd, str, ft_strlen(str));
        free(str);
}

void    check_opt(char *file, char *id)
{
        char    **arr = NULL;
        char    *str = NULL;
        char    charset[3];
        int     fd = 0;

        ft_strcpy(charset, "\n:");
        arr = str_to_tab(file, "\n:");
        for (int y = 0; y < count_rows(file, charset); y++) {
                if (y % 2 == 0 && arr[y][2] == id[0])
                        arr[y][0] = '2';
        }
        str = tab_to_str(arr);
        free(*arr);
        fd = open("./res/task.txt", O_WRONLY);
        write(fd, str, ft_strlen(str));
        free(str);
}

void    edit_opt(char *file, char *id, char *new)
{
        char    **arr = NULL;
        char    *str = NULL;
        char    charset[3];
        int     fd = 0;

        arr = str_to_tab(file, "\n:");
        for (int y = 0; y < count_rows(file, charset); y++) {
                if (y % 2 == 0 && arr[y][2] == id[0])
                        arr[y + 1] = ft_strdup(new);
        }
        str = tab_to_str(arr);
        free(*arr);
        fd = open("./res/task.txt", O_WRONLY);
        write(fd, str, ft_strlen(str));
        free(str);
}

void    add_opt(char *file, char *task)
{
        char    *new = NULL;
        int     fd = 0;

        new = malloc(sizeof(char) * ft_strlen(file) + ft_strlen(task) + 4);
        ft_strcat(new, file);
        ft_strcat(new, "0.0\n");
        ft_strcat(new, task);
        fd = open("./res/task.txt", O_WRONLY);
        write(fd, new, ft_strlen(new));
        free(new); 
}

void	del_opt(char *file, char *id)
{
		char	*str = NULL;
		int		rows = 0;
		int		index = -1;

		(void)id;
		str = ft_strdup(file);
		for (int i = 0; str[i] != '\0'; i++) {
				if (str[i] == ':' || str[i] == '\n')
					rows++;
				if (rows % 2 == 0 && ft_strncmp(&str[i + 2], id, ft_strlen(id))) {
						index = i;
						break;
				}
		}
		printf("index = %d\n", index);
}

bool    is_option(int ac, char **av, char *buf)
{
        if (ac == 3 && ft_strcmp(av[1], "-a")) {
                add_opt(buf, av[2]);
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
                del_opt(buf, av[2]);
                return true;
        }
        if (ac == 4 && ft_strcmp(av[1], "-e") && is_num(av[2])) {
                edit_opt(buf, av[2], av[3]);
                return true;
        }
        return false;
}
