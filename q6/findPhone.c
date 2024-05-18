#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("ERROR! too few arguments\n");
        printf("Usage: ./findPhone <name>\n");
    }
    int pipefd1[2];
    int pipefd2[2];

    if (pipe(pipefd1) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd2) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) // Child process. Try to run grep command and return the result to the parent process
    {
        close(pipefd1[0]); // Close unused read end

        if (dup2(pipefd1[1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        // Execute grep command and write the result to the pipe. If the command fails, it will continue to the next line and print an error
        execlp("grep", "grep", argv[1], "phoneBook", NULL);

        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else // Parent process. Will create another pipe and run the cut command by the child process
    {
        close(pipefd1[1]); // Close unused write end

        // Wait for the first child process to finish
        wait(NULL);

        int pid2 = fork();

        if (pid2 == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) // The second child process
        {
            close(pipefd2[0]); // Close unused read end

            if (dup2(pipefd1[0], STDIN_FILENO) == -1)
            {
                perror("dup2");
                exit(EXIT_FAILURE);
            }

            // Execute cut command and write the result to the command line. If the command fails, it will continue to the next line and print an error
            execlp("cut", "cut", "-d", ",", "-f", "2", NULL);

            perror("execlp");
            exit(EXIT_FAILURE);
        }
        else // Parent proces
        {
            close(pipefd2[1]); // Close unused write end

            // Wait for second child process to finish
            wait(NULL);

            // Close the read end of the second pipe
            close(pipefd2[0]);
        }

        // Close the read end of the first pipe
        close(pipefd1[0]);
    }

    return 0;
}
