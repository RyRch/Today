#include "../icl/proto.h"

char    *ft_strcpy(char *dest, char *src)
{
        for (int i = 0; src[i] != '\0'; i++)
                dest[i] = src[i];
        dest[ft_strlen(src)] = '\0';
        return (dest);
}
