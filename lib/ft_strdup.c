#include "../icl/proto.h"

char    *ft_strdup(char *src)
{
        char	*new = NULL;

        new = malloc(sizeof(char) * ft_strlen(src) + 1);
        if (new == NULL)
                return (NULL);
        ft_strcpy(new, src);
        return (new);
}
