#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *file;

    file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  // Child process
        fprintf(file, "Child PID: %d\n", getpid());
        printf("Child process wrote to file\n");
    } else {    // Parent process
        wait(NULL);
        fprintf(file, "Parent PID: %d\n", getpid());
        printf("Parent process wrote to file\n");
    }

    fclose(file);
    return 0;
}
