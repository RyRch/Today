#include "../icl/icl.h"

int	ft_strlen(char *str) 
{
        int i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

char    *ft_strdup(char *src)
{
        char	*new;
        int		i;

        i = 0;
        new = malloc(sizeof(char) * ft_strlen(src) + 1);
        if (new == NULL)
                return (NULL);
        while (src[i]) {
                new[i] = src[i];
                i++;
        }
        new[i] = '\0';
        return (new);
}

bool ft_strcmp(char *s1, char *s2)
{
        for (int i = 0; s1[i]; i++) {
                if (s1[i] != s2[i])
                        return false;
        }
        return true;
}

bool    is_num(char *str)
{
        for (int i = 0; str[i]; i++) {
                if (str[i] < '0' && str[i] > '9')
                        return false;
        }
        return true;
}
