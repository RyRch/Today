#include "../icl/proto.h"

char	*sort_index(char *buf)
{
	char **arr = str_to_tab(buf, "\n:");
	char **tab = NULL;
	int	x = 0;
	char tmp = '0';
	char *str = NULL;

	for (int i = 0; arr[i] != NULL; i++) {
		if (i % 2 == 0) {
			tab = str_to_tab(arr[i], ".");
			tmp = x + '0';
			tab[1] = ft_strcpy(&arr[i][2], &tmp);
			arr[i] = NULL;
			arr[i] = malloc(sizeof(char) * 1000);
			ft_strcat(arr[i], tab[0]);
			ft_strcat(arr[i], ".");
			ft_strcat(arr[i], tab[1]);
			x++;
		}			
	}
	str = ft_strdup(tab_to_str(arr));
	return (str);
}

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
		ft_strcat(new, "\n");
		fd = open("./res/task.txt", O_WRONLY);
		write(fd, sort_index(new), ft_strlen(new) + 1);
		free(new); 
}

void	del_opt(char *file, char *id)
{
		char	*new = NULL;
		int		rows = 0;
		int		index = -1;
		int		x = 0;
		int		y = 0;
		int		fd = 0;

		new = malloc(sizeof(char) * ft_strlen(file));
		for (int i = 0; file[i] != '\0'; i++) {
				if (file[i] == ':' || file[i] == '\n')
						rows++;
				if (rows % 2 == 0 && ft_strncmp(&file[i + 2], id, ft_strlen(id))) {
						index = i;
						y = rows;
				}
				if (index != -1 && rows == y + 2)
						x = i;
		}
		new = ft_strncpy(new, file, index + 2);
		if (ft_strlen(&file[x]) > 3)
			ft_strcat(new, &file[x]);
		fd = open("./res/task.txt", O_WRONLY | O_TRUNC);
		write(fd, sort_index(new), ft_strlen(new) + 2);
		free(new);
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
