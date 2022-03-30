#include <sys/types.h>
#include "../icl/proto.h"

char *reverse(char *str)
{
    char tmp, *src, *dst;
    size_t len;
    if (str != NULL)
    {
        len = ft_strlen(str);
        if (len > 1) {
            src = str;
            dst = src + len - 1;
            while (src < dst) {
                tmp = *src;
                *src++ = *dst;
                *dst-- = tmp;
            }
        }
    }
    return str;
}

void ft_itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)        /* record sign */
        n = -n;                /* make n positive */
    i = 0;

    do {                       /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0);   /* delete it */

    if (sign < 0)
        s[i++] = '-';

    reverse(s);
    s[i] = '\0';
    return;
}
