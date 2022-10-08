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
  

int main() {
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("prog", 0);
    
    // msgget creates a message queue
    // and returns identifier

    int maxIdx = 0, curIdx = 0;
    while(1) {
        while(curIdx < maxIdx + 5) {
            msgid = msgget(key, 0666 | IPC_CREAT);
            msgrcv(msgid, &message, sizeof(message), 1, 0);
			sleep(1);
            msgctl(msgid, IPC_RMID, NULL);
            message.mesg_text[sizeof(message.mesg_text) - 1] = 0;
            curIdx = message.mesg_text[0];
			printf("STRING SENT BY CLIENT: ");		
            for(int i = 1; i < 12; i++) {
				printf("%c", message.mesg_text[i]);
			}
            printf("\n");
			sprintf(message.mesg_text, "%d", curIdx);

			printf("ID SENT BY CLIENT = %s\n", message.mesg_text);	
        }

        
        maxIdx = curIdx;
        msgid = msgget(key, 0666 | IPC_CREAT);
        msgsnd(msgid, &message, sizeof(message), 0);
        msgctl(msgid, IPC_RMID, NULL);
        if(maxIdx >= 50) break;
    }


    msgctl(msgid, IPC_RMID, NULL);
  
    return 0;
}