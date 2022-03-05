#include "../icl/icl.h"

bool    is_num(char *str)
{
        for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] < '0' && str[i] > '9')
                        return false;
        }
        return true;
}
