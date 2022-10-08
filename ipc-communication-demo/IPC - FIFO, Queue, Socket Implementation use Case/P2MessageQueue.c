#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
  
// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;
  

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
    key_t key;
    int msgid;
  
    // ftok to generate unique key
    key = ftok("prog", 0);
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
    // msgget creates a message queue
    // and returns identifier
    message.mesg_type = 1;
    
    int lastIdx = 1;
    while(1) {
        for(int i = lastIdx; i < lastIdx + 5; i++) {
            msgid = msgget(key, 0666 | IPC_CREAT);
            strncpy(message.mesg_text, randStr[i], sizeof(randStr[i]) + 1);
            msgsnd(msgid, &message, sizeof(message), 0);
			sleep(1);
            msgctl(msgid, IPC_RMID, NULL);
        }

        msgid = msgget(key, 0666 | IPC_CREAT);
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        msgctl(msgid, IPC_RMID, NULL);
        message.mesg_text[sizeof(message.mesg_text) - 1] = 0;
        
        int finalIdx = atoi(message.mesg_text);
 		printf("MAX ID SENT BACK BY SERVER = %s\n\n", message.mesg_text);
        
        lastIdx = finalIdx + 1;

        if(lastIdx >= 50) {
            msgctl(msgid, IPC_RMID, NULL);
            break;
        }
    }

    return 0;
}