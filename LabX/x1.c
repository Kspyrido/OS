#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++){
        pid_t pid = fork();
        if (pid == 0){
	    //Child process
	    printf("Child process with PID: %d\n", getpid());
	}else if (pid > 0){
	    //Parent process
	    printf("Parent process with PID: %d created a child with PID %d\n", getpid(), pid);
	    break;
	}else{
	    //Fork failed
	    perror("fork");
	}

    }
    return 0;
}
