#include <stdio.h>
#include <sys/wait.h>   
#include <unistd.h>     
#include <stdlib.h>

int main(void)
{
    int N, T; scanf("%i %i", &N, &T);
    printf("CREATING %d CHILDREN, SLEEPING FOR %d SECONDS AND EXECUTING 'ps -aux' FOR EACH CHILDREN\n\n", N, T);

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
            printf("[CHILD %d]: Sleeping for %d seconds and then executing 'ps -aux'\n", i, T);
            sleep(T);                                                           
            
            execlp("ps", "ps", "aux", (char *)NULL);                            // Thanks stack overflow
            
            perror("I failed to execute execlp, cry about it\n");
            return 666;
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