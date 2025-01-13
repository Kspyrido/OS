#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("pid_file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        dprintf(fd, "Child PID: %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        dprintf(fd, "Parent PID: %d\n", getpid());
    } else {
        perror("fork");
        return 1;
    }

    close(fd);
    return 0;
}
