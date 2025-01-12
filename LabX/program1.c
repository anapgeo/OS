#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child process with PID: %d\n", getpid());
        } else if (pid > 0) {
            printf("Parent process with PID: %d\n", getpid());
        } else {
            perror("Fork failed");
            return 1;
        }
    }
    return 0;
}
