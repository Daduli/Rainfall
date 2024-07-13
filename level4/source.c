#include <stdio.h>
#include <stdlib.h>

void p(char *param1)
{
    printf(param1);
    return;
}

void n(void)
{
    char local20[520];

    fgets(local20, 512, stdin);
    p(local20);
    if (m == 16930116)
    {
        system("/bin/cat /home/user/level5/.pass");
    }
    return;
}

int main(void)
{
    n();
    return 0;
}