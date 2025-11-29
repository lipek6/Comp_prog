#include <stdio.h>
#include <sys/wait.h>   
#include <unistd.h>     
#include <stdlib.h>

int main(void)
{
    int N, T; scanf("%i %i", &N, &T);
    printf("CREATING %d CHILDREN AND PUTTING THEN TO SLEEP FOR %d SECONDS\n\n", N, T);

    for(int i = 1; i <= N; i++)                                                  
    {
        pid_t pid = fork();                                                     // Fork a child process.

        if(pid < 0)                                                             // Error occurred.
        { 
            fprintf(stderr, "Fork failed!\n");
            return 1;
        }

        else if(pid == 0)                                                       // Child process.
        {
            printf("[CHILD %d]: PID: %d - PPID: %d\n", i, getpid(), getppid());       
            printf("[CHILD %d]: It's time to sleep for %d seconds\n", i, T);
            sleep(T);                                                           
            printf("[CHILD %d]: Terminating myself now (PID: %d)\n", i, getpid());
            return 0;
        }

        else
        {
            printf("[PARENT]:  PID: %d - CHILD %d: %d\n", getpid(), i, pid);

            int wstatus;
            wait(&wstatus); 
            if (WIFEXITED(wstatus))
            {
                printf("[PARENT]:  Child %d returned with code %d.\n\n", i, WEXITSTATUS(wstatus));
            }
        }
    }
    return 0;
}