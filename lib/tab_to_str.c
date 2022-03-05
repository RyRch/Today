#include "../icl/proto.h"

char *tab_to_str(char **arr)
{
        char *str = NULL;
        int total = 0;
        int rows = 0;

        for ( ; arr[rows] != NULL; rows++)
                total += ft_strlen(arr[rows]);
        str = malloc(sizeof(char) * (total + rows + 1));
        str[0] = 0;
        for (int y = 0; y < rows; y++) {
                ft_strcat(str, arr[y]);
                ft_strcat(str, "\n");
        }
        str[ft_strlen(str)] = '\0';
        return (str);
}
