#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX_MSG_SIZE 2048
void main(){
    int fd1, fd2; 
    char lettura [2048];
    char scrittura[2048];
    fd1= open("myfifo", O_WRONLY);
    fd2= open("myfifo2",O_RDONLY);
    printf("la chat si sta per aprire, scrivi 'HALT' per terminare\n");
do{
   printf("\033[0;35muser1: \033[0m");
      fgets(scrittura, MAX_MSG_SIZE, stdin);
        
        write(fd1, scrittura, strlen(scrittura) + 1); 

        read(fd2, lettura, sizeof(lettura)); 
        printf("\033[0;32muser2: %s\033[0m\n", lettura); 

     
        
       
        
    } while (strcmp(lettura, "HALT\n") != 0 && strcmp(scrittura, "HALT\n") != 0);
    
    close(fd1);
    close(fd2);
   



}