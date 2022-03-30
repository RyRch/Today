#include "../icl/proto.h"
#include <stdlib.h>

void    write_to_file(p_s *list)
{
        char    *str = NULL;
        int     fd = 0;

        str = list_to_str(list);
		fd = open("/home/rr/.today", O_WRONLY | O_TRUNC);
        str = ft_strdup(list_to_str(list));
		write(fd, str, ft_strlen(str) + 1);
		free(str); 
}

void    add_opt(p_s *list, char *task)
{
        p_s     *tmp = NULL;

        tmp = create_node(task, 0, 0);
        tmp->next = list;
        list = tmp;
        sort_index(list);
        write_to_file(list);
}

void    status_opt(p_s *list, int status, char **av)
{
        p_s *tmp = list; 
        p_s *head = tmp;
        p_s *prev = tmp;
        p_s *headp = prev;
        int x = 0;
        int dcheck = 0;

        while (tmp != NULL) {
                for (int i = 2; av[i] != NULL; i++) {
                        if (atoi(av[i]) == tmp->index && status == BEGIN)
                                tmp->status = DOING;
                        else if (atoi(av[i]) == tmp->index && status == CHECK)
                                tmp->status = DONE;
                        else if (tmp->index == atoi(av[i]) && status == DELETE) {
                                prev->next = tmp->next;
                                dcheck = 1;
                        }
                }
                if (atoi(av[2]) == tmp->index && status == EDIT)
                        tmp->task = ft_strdup(av[3]);
                if (x >= 1)
                        prev = prev->next;
                tmp = tmp->next;
                x++;
        }
        if (dcheck == 1)
                head = headp;
        sort_index(head);
        write_to_file(head);
}

bool    is_option(int ac, char **av, p_s **head)
{
		if (ac == 3 && ft_strcmp(av[1], "-a")) {
				add_opt(*head, av[2]);
				return true;
		} else if (ft_strcmp(av[1], "-b")) {
				status_opt(*head, BEGIN, av);
				return true;
		} else if (ft_strcmp(av[1], "-c")) {
				status_opt(*head, CHECK, av);
				return true;
        } else if (ft_strcmp(av[1], "-d")) {
			    status_opt(*head, DELETE, av);
				return true;
		} else if (ac == 4 && ft_strcmp(av[1], "-e")) {
			    status_opt(*head, EDIT, av);
				return true;
		}
		return false;
}
