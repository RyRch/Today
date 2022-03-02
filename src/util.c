#include "../icl/icl.h"

int	ft_strlen(char *str) 
{
        int i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

char    *ft_strcpy(char *dest, char *src)
{
        for (int i = 0; src[i]; i++)
                dest[i] = src[i];
        dest[ft_strlen(src)] = '\0';
        return (dest);
}

char    *ft_strdup(char *src)
{
        char	*new;

        new = malloc(sizeof(char) * ft_strlen(src) + 1);
        if (new == NULL)
                return (NULL);
        ft_strcpy(new, src);
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
