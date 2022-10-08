# Inter-Process Communications 

There are 3 Programs in this file to test Inter-Process Communications between processes, The first one used Sockets, the Second uses FIFO(Named Pipes), and Message Queues.
The first Part of all the programs is the same, where we generate 50 random strings of length 10. Then we send strings from the from the first process to the second process where we first print the string that was sent by the first process, further if we 5 strings have been send to the the second process it sends an acknoledgement to the first process in the form of the highest index string recieved. The first process then proceeds to send the next five strings. This process goes on till we Exhaust all strings, i.e. The second process sends back a max index of 50.

<br>

## Building and running the programs

In the directory, run the command

    make

For Testing/Running Sockets run the commands in one terminal in the given order
    
    ./P2socket &
    ./P1socket

For Testing/Running FIFO run the commands in two different Terminals in the given order

    ./P2FIFO
    ./P1FIFO

For Testing/Running Message Queue run the commands in two different Terminals in the given order

    ./P2MessageQueue
    ./P1MessageQueue

For deleting the object files run

    make clean

<br>

## Generating 50 Random Strings

In all the P1s there is a function defined as ```void getRandStr(char *)``` which uses ```rand() % 26``` defined in gcc to get a number number in the range of 0 to 25, we then add the ascii of 'A' to it that is 65 to get a random character in the range of 'A' to 'Z', we also use the 0th index of the every string to store the index of it. That is say the 4th random string generated is ```ABCDEFGHIJ``` then the character array stored will be ```ascii('4')ABCDEFGHIJ```

<br>

<i>The main interprocess communication task remains the same accross all three programs which has been explained above. The specific functionalities of the Three Types have been given below</i>

<br>

## Using Socket
An ```AF_UNIX``` socket has been used as the interprocess communications are local.<br>
```sockaddr_un structure``` has been used to create and use the Socket which is then initialised by ```AF_UNIX``` by ```addr.sun_family = AF_UNIX``` where addr is the name of the struct. We then create a data socket and connect it to adde using ```connect(data_socket, (const struct sockaddr *) &addr, sizeof(addr))```<br>
The above two steps are done in both P1 and P2<br>
Then we use ```write(data_socket, char *, sizeof(char *))``` and ```read(data_socket, char *, sizeof(char *))``` to read and write using the data socket we made.<br>

<br>

## Using FIFO
For this Implementation two FIFOs have been created in the following fashion

    P1 writes into FIFO1
    P2 reads from FIFO1
    P2 writes into FIFO2
    P1 reads from FIFO2

This is done to prevent in unnecessary read writes from FIFOs while the other is trying to communicate.

Firstly ```mkfifo(char *, int)``` is used to create the FIFOs.<br>
Then For every read or write command firstly we open the required FIFO by using ```open(char *, int)``` with necessary specifiers like ```O_WRONLY``` or ```RD_ONLY``` to open the FIFO<br> which returns the file descriptor 
Then to read or write we use ```read(int fd, char *, sizeof(char *))``` and ```write(int fd, char *, sizeof(char *))```<br>
Finally we use ```close(int fd)``` to close the FIFO

<br>

## Using Message Queues
For this we need to use a structure to communicate that has two arributes

    long mesg_type
    char * mesg_text

mesg_type will be set to a positive value

firstly ```ftok(char *, int)``` is used to generate an unique key<br>
then we use ```msgid = msgget(key, 0666 | IPC_CREAT)``` to create a message queue with ```msgid``` acting as a fd<br>
For read and write we use ```msgrcv(msgid, &message, sizeof(message), 1, 0)``` and ```msgsnd(msgid, &message, sizeof(message), 0)``` where message is an object of the initially described structure<br>
Finally ```msgctl(msgid, IPC_RMID, NULL)``` is used to close the Message Queue

<br>

## References

https://man7.org/linux/man-pages/man7/unix.7.html <br>
https://www.geeksforgeeks.org/ipc-using-message-queues/?ref=lbp <br>
https://www.geeksforgeeks.org/named-pipe-fifo-example-c-program/






