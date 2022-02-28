#ifndef ICL_H

# define ICL_H

#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

bool    is_charset(char c, char *str);
int	    count_rows(char *str, char *charset);
int	    *count_cols(char *str, char *charset);
char	**str_to_tab(char *str, char *charset);

typedef struct t_s {
    char *buf;
} t_s;

#endif
