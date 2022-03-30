#ifndef ICL_H
# define ICL_H

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

bool    is_charset(char c, char *str);
int	    count_rows(char *str, char *charset);
int	    *count_cols(char *str, char *charset);
char	**str_to_tab(char *str, char *charset);
int     ft_strlen(char *str);
char    *ft_strdup(char *src);
bool    ft_strcmp(char *s1, char *s2);
bool    is_num(char *str);
bool    is_option(int ac, char **av, p_s **head);
void    print_arr(char **arr);
char    *ft_strcpy(char *dest, char *src);
char    *ft_strcat(char *dest, char *src);
char    *tab_to_str(char **arr);
bool	ft_strncmp(char *s1, char *s2, int n);
char	*ft_strncpy(char *dest, char *src, int n);
void    print_list(p_s *head);
void    add_opt(p_s *list, char *task);
char    *list_to_str(p_s *list);
void    sort_index(p_s *head);
void    ft_itoa(int n, char s[]);
p_s     *create_node(char *task, int index, int status);
p_s     *str_to_list(char **arr);

#endif
