#include "../icl/proto.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
		int	i = 0;

		for ( ; i < n; i++)
				dest[i] = src[i];
		dest[i] = '\0';
		return (dest);
}
