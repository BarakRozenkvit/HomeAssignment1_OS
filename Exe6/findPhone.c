#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {

    if (argc == 2) {

        int pipe1[2], pipe2[2], pipe3[2];

        pipe(pipe1);
        pipe(pipe2);
        pipe(pipe3);

        int pid1 = fork();
        if (!pid1) {

            close(pipe1[0]);
            dup2(pipe1[1], 1);
            close(pipe1[1]);

            execlp("grep","grep", argv[1],"phonebook.txt",NULL);
        }
        else {

            int pid2 = fork();
            if(!pid2) {

                close(pipe1[1]);
                close(pipe2[0]);
                dup2(pipe1[0], 0);
                dup2(pipe2[1], 1);
                close(pipe1[0]);
                close(pipe2[1]);

                execlp("sed","sed", "s/ /#/g",NULL);
            }
            else{

                int pid3 = fork();
                if(!pid3) {

                    close(pipe1[1]);
                    close(pipe1[0]);
                    close(pipe2[1]);
                    close(pipe3[0]);
                    dup2(pipe2[0], 0);
                    dup2(pipe3[1], 1);
                    close(pipe2[0]);
                    close(pipe3[1]);

                    execlp("sed","sed","s/,/ /",NULL);
                }
                else{

                    int pid4 = fork();
                    if(!pid4) {

                        close(pipe1[0]);
                        close(pipe1[1]);
                        close(pipe2[0]);
                        close(pipe2[1]);
                        close(pipe3[1]);
                        dup2(pipe3[0], 0);
                        close(pipe3[0]);

                        execlp("awk","awk","{print$2}",NULL);
                    }

                    else{
                        close(pipe1[0]);
                        close(pipe1[1]);
                        close(pipe2[0]);
                        close(pipe2[1]);
                        close(pipe3[0]);
                        close(pipe3[1]);
                    }
                }
            }
        }
        wait(NULL);
        return 0;
    }
    else{
        perror("3 argumnets needed");
        return 1;
    }
}