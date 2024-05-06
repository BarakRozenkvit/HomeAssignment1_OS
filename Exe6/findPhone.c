#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc,char* argv[]) {

    if (argc != 2) {
        perror("1 word argumnet needed");
        return 1;
    }

    int pipe1[2], pipe2[2], pipe3[2];

    int res1 = pipe(pipe1);
    int res2 = pipe(pipe2);
    int res3 = pipe(pipe3);

    // if pipe failed
    if(res1 == -1 || res2 == -1 || res3 == -1){
        perror("failed create pipes");
        return 1;
    }

    int stat;

    int pid1 = fork();
    if (pid1 == 0) {
        // Replacing STDOUT <-> pipe1[1]
        close(1);
        dup(pipe1[1]);
        // closing unused ends
        close(pipe1[0]);

        // executing grep with execlp
        execlp("grep", "grep", argv[1], "phonebook.txt", NULL);
        // if failed
        perror("grep");
        exit(1);
    }
    // if fork failed
    else if(pid1 < 0){
        perror("failed creating fork");
        return 1;
    }
    else{
        // closing pipe1[1] and waiting for pid1
        close(pipe1[1]);
        waitpid(pid1,&stat,0);
    }

    int pid2 = fork();
    if (pid2 == 0) {
        // Replacing STDIN <-> pipe1[0]
        close(0);
        dup(pipe1[0]);
        // Replacing STDOUT <-> pipe2[1]
        close(1);
        dup(pipe2[1]);
        // closing unused ends
        close(pipe1[1]);
        close(pipe2[0]);

        execlp("sed", "sed","s/ /#/g", NULL);
        perror("sed");
        exit(1);
    }
    else if(pid2 < 0){
        perror("failed creating fork");
        return 1;
    }
    else {
        close(pipe1[0]);
        close(pipe2[1]);
        waitpid(pid2, &stat, 0);
    }


    int pid3 = fork();
    if (pid3 == 0) {
        // Replacing STDIN <-> pipe2[0]
        close(0);
        dup(pipe2[0]);
        // Replacing STDOUT <-> pipe3[1]
        close(1);
        dup(pipe3[1]);
        // closing unused ends
        close(pipe2[1]);
        close(pipe3[0]);


        execlp("sed", "sed", "s/,/ /", NULL);
        perror("sed");
        exit(1);
    }
    else if(pid3 < 0){
        perror("failed creating fork");
        return 1;
    }
    else {
        close(pipe2[0]);
        close(pipe3[1]);
        waitpid(pid3, &stat, 0);
    }

    int pid4 = fork();
    if (pid4 == 0) {
        // Replacing STDIN <-> pipe3[0]
        close(0);
        dup(pipe3[0]);
        // closing unused ends
        close(pipe3[1]);

        execlp("awk", "awk", "{print $2}", NULL);
        perror("awk");
        exit(1);
    }
    else if(pid4 < 0){
        perror("failed creating fork");
        return 1;
    }
    else {
        close(pipe3[0]);
        waitpid(pid4, &stat, 0);
    }

    return 0;
}
