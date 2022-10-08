#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/un.h>
#define BUFFER_SIZE 100


int main() {
    int fd1, fd2;

    int ret;
    char buffer[BUFFER_SIZE];
	int maxIdx = 0;
    // FIFO file path
    char * myfifo1 = "FIFO1";
    char * myfifo2 = "FIFO2";

    
    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);


	maxIdx = 0;
	int curIdx = maxIdx;
	while(1) {
		while(curIdx < maxIdx + 5) {
			sleep(2);
			fd1 = open(myfifo1, O_RDONLY);
			ret = read(fd1, buffer, sizeof(buffer));
			close(fd1);
			if(ret == -1) {	
				perror("couldn't read");
				exit(EXIT_FAILURE);
			}
			curIdx = buffer[0];
			printf("STRING SENT BY CLIENT: ");		
			
			for(int i = 1; i < 12; i++) {
				printf("%c", buffer[i]);
			}
			printf("\n");
			
			sprintf(buffer, "%d", curIdx);
			printf("ID SENT BY CLIENT = %s\n", buffer);	
		}
		//buffer contains the string with the 0th idx as the index of the string
		
		maxIdx = curIdx;
		fd2 = open(myfifo2, O_WRONLY);
		ret = write(fd2, buffer, sizeof(buffer));
		close(fd2);
		// break;
		if(maxIdx >= 50) exit(EXIT_SUCCESS);
	}
    return 0;
}