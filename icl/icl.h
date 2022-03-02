#ifndef ICL_H

# define ICL_H

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct t_s {
    char *buf;
    char **arr;
} t_s;

bool    is_charset(char c, char *str);
int	    count_rows(char *str, char *charset);
int	    *count_cols(char *str, char *charset);
char	**str_to_tab(char *str, char *charset);
int     ft_strlen(char *str);
char    *ft_strdup(char *src);
bool    ft_strcmp(char *s1, char *s2);
bool    is_num(char *str);
bool    is_option(int ac, char **av, char *buf);
void    print_arr(char **arr);
char    *ft_strcpy(char *dest, char *src);

#endif
