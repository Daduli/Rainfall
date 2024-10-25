#include <stdlib.h>
#include <string.h>

int n()
{
	return(system("/bin/cat /home/user/level7/.pass"));
}

int m()
{
	return(puts("Nope"));
}

int main(int argc, const char **argv, const char **envp)
{
	int (**ptr)(void);
	char *buffer;

	buffer = (char *)malloc(64);
	ptr = (int (**)(void))malloc(4);
	*ptr = m;
	strcpy(buffer, argv[1]);
	return (*ptr)();
}