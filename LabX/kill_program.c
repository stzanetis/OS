#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handle_signal(int sig) {
    printf("Child process received signal via kill\n");
    exit(0);
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {	// Child process
        signal(SIGUSR1, handle_signal);
        while (1) {
            printf("Child process waiting for signal..\n");
            sleep(1);
        }
    } else {	// Parent process
        sleep(2);
        printf("Parent process sending signal to child\n");
        kill(pid, SIGUSR1);
        wait(NULL);
        printf("Child process terminated\n");
    }

    return 0;
}
