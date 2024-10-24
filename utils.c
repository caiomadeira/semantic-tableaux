#include "utils.h"

void rmspc(char *str)
{
    if (*str == '\0')
        return;
    if (*str == ' ')
    {
        char *p = str;
        while (*(p + 1) != '\0')
        {
            *p = *(p + 1);
            p++;
        }
        *p = '\0';
        rmspc(str);
    }
    else
        rmspc(str + 1);
}