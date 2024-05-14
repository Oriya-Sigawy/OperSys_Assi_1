
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd = open("phoneBook", O_APPEND | O_CREAT | O_WRONLY, S_IRWXU);
    if (fork() == 0)
    {
        dup2(fd, STDOUT_FILENO);
        char **args = (char **)malloc(sizeof(char *) * (argc + 1));
        for (int i = 0; i < argc; i++)
        {
            args[i] = strdup(argv[i]);
        }
        args[argc] = NULL;
        int result = execvp("echo", args);
    }
}