#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int n, i;
    char message[100] = "Start";   // Initial message

    printf("Enter number of levels: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        pid_t pid = fork();

        if(pid == 0)
        {
            // Child process: modify message
            char temp[10];
            sprintf(temp, "->P%d", i);
            strcat(message, temp);

            printf("Level %d (PID %d): %s\n", i, getpid(), message);
        }
        else
        {
            // Parent waits and stops creating further children
            wait(NULL);
            break;
        }
    }

    return 0;
}
