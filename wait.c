#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    char const *message = NULL;

    int n;
    int exit_code;

    printf("fork program starting\n");

    pid = fork();

    switch (pid) 
    {
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = 5;
            exit_code = 37;
            break;
        default:
            message = "This is the parent";
            n = 3;
            exit_code = 0;
            break;
    }

    for (; n > 0; n--)
    {
        puts(message);
        sleep(1);
    }

    if (0 != pid) // 父进程

    {
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);

        printf("Child has finished: PID = %d\n", child_pid);

        if (WIFEXITED(stat_val))
        {
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        }
        else
        {
            printf("Child terminated abnormally\n");
        }
    }

    exit(exit_code);
}
