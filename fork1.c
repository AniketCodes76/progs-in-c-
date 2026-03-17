#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    // First fork
    pid1 = fork();

    if (pid1 == 0) {
        // Child 1 process
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Second fork inside Child 1
        pid2 = fork();

        if (pid2 == 0) {
            // Grandchild process
            printf("Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else {
            printf("Child 1 created Grandchild with PID = %d\n", pid2);
        }

    } else {
        // Parent process
        printf("Parent: PID = %d, Created Child 1 with PID = %d\n", getpid(), pid1);
    }

    return 0;
}