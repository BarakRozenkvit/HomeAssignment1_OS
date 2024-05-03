#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char* argv[]) {
    if (argc==3 || argc == 4) {

        int fb_fds = open("phonebook.txt", O_WRONLY | O_APPEND);

        close(1);
        dup(fb_fds);
        close(fb_fds);
        if(argc == 4) {
            printf("%s %s,%s\n", argv[1], argv[2], argv[3]);
        }
        else{
            printf("%s,%s\n",argv[1],argv[2]);
        }

        close(fb_fds);
        return 0;

    }
    else {
        perror("expected 1 argumnet");
        return 1;
    }
}
