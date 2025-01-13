#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig) {
    printf("Child received signal %d from parent\n", sig);
    exit(0);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler);
        printf("Child waiting for signal...\n");
        pause(); // Wait for signal
    } else if (pid > 0) {
        // Parent process
        sleep(1); // Give child time to set up signal handler
        printf("Parent sending signal to child (PID: %d)\n", pid);
        kill(pid, SIGUSR1);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}
