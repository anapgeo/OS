#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Child received signal: %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        signal(SIGUSR1, handle_signal);
        pause(); // Wait for signal
    } else if (pid > 0) { // Parent process
        sleep(1);
        kill(pid, SIGUSR1);
    } else {
        perror("Fork failed");
        return 1;
    }

    return 0;
}
