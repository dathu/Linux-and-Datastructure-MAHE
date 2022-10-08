#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "mySocket.socket"
#define BUFFER_SIZE 12

int main(int argc, char *argv[]) {
	struct sockaddr_un servername;
	int down_flag = 0;
	int connection_socket;
	int ret;
	int maxIdx = 0;
	int data_socket;
	char buffer[BUFFER_SIZE];

	connection_socket = socket(AF_UNIX, SOCK_SEQPACKET, 0);
	if(connection_socket == -1) {
		perror("Socket couldn't be made");
		exit(EXIT_FAILURE);
	}

	memset(&servername, 0, sizeof(servername));
	servername.sun_family = AF_UNIX;
	strncpy(servername.sun_path, SOCKET_NAME, sizeof(servername.sun_path) - 1);

	ret = bind(connection_socket, (const struct sockaddr *) &servername, sizeof(servername));

	if(ret == -1) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	ret = listen(connection_socket, 100);
	if(ret == -1) {
		perror("listen");
		exit(EXIT_FAILURE);
	}

	while(1) {
		data_socket = accept(connection_socket, NULL, NULL);
		if(data_socket == -1) {
			perror("couldn't accept");
			exit(EXIT_FAILURE);
		}

		maxIdx = 0;
		int curIdx = maxIdx;
		while(1) {
			ret = read(data_socket, buffer, sizeof(buffer));
			if(ret == -1) {
				perror("couldn't read");
				exit(EXIT_FAILURE);
			}

			buffer[sizeof(buffer) - 1] = 0;
			curIdx = buffer[0];

			if(!strncmp(buffer, "DOWN", sizeof(buffer))) {
				down_flag = 1;
				break;
			}

			//buffer contains the string with the 0th idx as the index of the string
			printf("STRING SENT BY CLIENT: ");		
			
			for(int i = 1; i < 11; i++) {
				printf("%c", buffer[i]);
			}

			printf("\n");
			sprintf(buffer, "%d", curIdx);
			printf("ID SENT BY CLIENT = %s\n", buffer);		

			if(curIdx == maxIdx + 5) {
				maxIdx = curIdx;
				ret = write(data_socket, buffer, sizeof(buffer));
			}	

			if(curIdx >= 50) break;
		}
		
		

		close(data_socket);

		if(down_flag) {
			printf("SHUTTING SERVER");
			close(connection_socket);
			unlink(SOCKET_NAME);
			exit(EXIT_SUCCESS);
			break;
		}
		
		if(ret == -1) {
			perror("write");
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}