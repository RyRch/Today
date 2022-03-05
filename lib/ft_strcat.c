#include "../icl/icl.h"

char *ft_strcat(char *dest, char *src)
{
        int len = ft_strlen(dest);

        for (int i = 0; src[i] != '\0'; i++)
                dest[len++] = src[i];
        dest[len] = '\0';
        return (dest);
}
