#include <stdio.h>
#include <unistd.h>     // For the syscall functions.
#include <sys/wait.h>   // For wait and related macros.
#include <stdlib.h>

int main()
{
    pid_t pid = fork(); // Fork a child process.

    if (pid < 0)
    { // Error occurred.
        fprintf(stderr, "Fork failed!\n");
        return 1;
    }

    else if (pid == 0)
    { // Child process.
        printf("[CHILD]:  My PID is %d and my PPID is %d.\n", getpid(), getppid());
        printf("[CHILD]:  Press 'E' to exit me.\n");
        char user_input;
        while(1)
        {
            scanf("%c", &user_input);
            if(user_input == 'e' || user_input == 'E') break;
        }
        printf("[CHILD]:  You pressed 'E', you murdered a child, monster.\n");

        exit(69);       // 69 is th ascii value of 'E'
    }
    
    else
    { // Parent process.
        printf("[PARENT]: My PID is %d.\n", getpid());
        printf("[PARENT]: Waiting on child.\n");
        int wstatus;
        wait(&wstatus);
        
        if (WIFEXITED(wstatus))
        {
            printf("[PARENT]: Child returned with code %d.\n", WEXITSTATUS(wstatus));

            if(WEXITSTATUS(wstatus) == 69)
                printf("[PARENT]: Child finished when someone pressed 'E', that's cool!\n");                
        }
        else if (WIFSIGNALED(wstatus))
        {
            printf("[PARENT]: They killed my child! He was killed by the signal %d.\n", WTERMSIG(wstatus));
            if(WTERMSIG(wstatus) == 9)
                printf("[PARENT]: Signal %d means that SIGKILL is the responsible for this!\n", WTERMSIG(wstatus));
            if(WTERMSIG(wstatus) == 15)
                printf("[PARENT]: Signal %d means that SIGTERM is the responsible for this!\n", WTERMSIG(wstatus));
            // I could go on, but I think this is enough to illustrate.
        }
    }

    return 0;
}
