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

void getRandStr(char randstrs[][12]) {        
    srand (time(NULL));                            
    for (int j = 0; j <= 50; j++) {
        randstrs[j][0] = j;
    }
    
    for(int i = 0; i <= 50; i++) {
		for(int j = 1; j <= 10; j++) {
			randstrs[i][j] = rand() % 26 + 65;
		}
	}
}

int main() {
    int fd1, fd2;

    int ret;
    char buffer[BUFFER_SIZE];
    // FIFO file path
    char * myfifo1 = "FIFO1";
    char * myfifo2 = "FIFO2";
    
    char randStr[51][12] = {{0}};

    getRandStr(randStr);
    
	for(int i = 1; i <= 50; i++) {
		for(int j = 0; j < 12; j++) {
			if(j == 0) {
				printf("%d ", randStr[i][j]);
			}
			else printf("%c", randStr[i][j]);
		}
		printf("\n");
	}

	printf("\n%s\n", "The above strings are random strings created");
	
    mkfifo(myfifo1, 0666);
    mkfifo(myfifo2, 0666);


	int lastIdx = 1;
	while(1) {
		if(fd1 == -1) {
			perror("Couldn't access FIFO1");
		}

		printf("sending Strings Indexed from %d to %d\n", lastIdx, lastIdx + 4);
		
		for(int i = lastIdx; i < lastIdx + 5; i++) {
			fd1 = open(myfifo1, O_WRONLY);
			ret = write(fd1, randStr[i], sizeof(randStr[i]) + 1);
			sleep(1);	
			close(fd1);
		}

		//Reading Acknowledgements
		fd2 = open(myfifo2, O_RDONLY);
		ret = read(fd2, buffer, sizeof(buffer));
		close(fd2);

		if(ret == -1) {
			perror("read");
			exit(EXIT_FAILURE);
		}

		int finalIdx = atoi(buffer);
 		printf("MAX ID SENT BACK BY SERVER = %s\n\n", buffer);
		// break;

		lastIdx = finalIdx + 1;
		if(lastIdx >= 50) exit(EXIT_SUCCESS);
	}

    return 0;
}