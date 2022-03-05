#include "../icl/icl.h"

int	ft_strlen(char *str) 
{
        int i;

        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}

char    *ft_strcpy(char *dest, char *src)
{
        for (int i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];
        dest[ft_strlen(src)] = '\0';
        return (dest);
}

char    *ft_strdup(char *src)
{
        char	*new;

        new = 0;
        new = malloc(sizeof(char) * ft_strlen(src) + 1);
        if (new == NULL)
                return (NULL);
        ft_strcpy(new, src);
        return (new);
}

bool ft_strcmp(char *s1, char *s2)
{
        for (int i = 0; s1[i] != '\0'; i++) {
                if (s1[i] != s2[i])
                        return false;
        }
        return true;
}

bool    is_num(char *str)
{
        for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] < '0' && str[i] > '9')
                        return false;
        }
        return true;
}

char *ft_strcat(char *dest, char *src)
{
        int len = ft_strlen(dest);

        for (int i = 0; src[i] != '\0'; i++)
                dest[len++] = src[i];
        return (dest);
}
