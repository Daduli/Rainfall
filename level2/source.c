#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void p(void)
{
    unsigned int overflow_checker;
    char buffer[76];

    fflush(stdout);
    gets(buffer);
    if ((overflow_checker & 0xb0000000) == 0xb0000000)
    {
        printf("(%p)\n", overflow_checker);
        exit(1);
    }
    puts(buffer);
    strdup(buffer);
    return;
}

int main(void)
{
    p();
    return 0;
}