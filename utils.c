#include "utils.h"

void printVector(int* v, int n)
{
    for(int i = 0; i < MAX_CANDIDATES; i++)
        printf("%d\n", v[i]);
}

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