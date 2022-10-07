#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>        
int main()
        {
               int res;
               res = mkfifo("fifo1",0777); //creates a named pipe with the name fifo1
               printf("named pipe created\n");
        }
