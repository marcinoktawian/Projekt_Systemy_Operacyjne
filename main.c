#include <stdio.h>
#include <unistd.h>

int main() {

    int pid[3];

    pid[0] = fork();
    if(pid[0] == 0){
        int ret;
        char *envp[] = { NULL };
        char *argv[] = { "./m", "hello", "there", NULL };
        ret = execve("./m", argv, envp);
    }

    pid[1] = fork();
    if(pid[1] == 0){
        int ret;
        char *envp[] = { NULL };
        char *argv[] = { "./m", "hello", "there", NULL };
        ret = execve("./m", argv, envp);
    }

    pid[2] = fork();
    if(pid[2] == 0){
        int ret;
        char *envp[] = { NULL };
        char *argv[] = { "./m", "hello", "there", NULL };
        ret = execve("./m", argv, envp);
    }


    printf("\n\nHello World\n\n");



    return 0;
}