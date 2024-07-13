#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int passcode;
    char *cmd;
    __uid_t uid;
    __gid_t gid;

    passcode = atoi(*(char**) ac + 4);
    if (passcode == 423)
    {
        cmd = strdup("/bin/sh");
        gid = getegid();
        uid = geteuid();
        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);
        execv("/bin/sh", &cmd);
    }
    else
    {
        fwrite("No !\n",1,5,(FILE *)stderr);
    }
    return 0;
}