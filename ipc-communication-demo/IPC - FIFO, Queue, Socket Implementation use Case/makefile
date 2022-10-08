all: P1FIFO P2FIFO P1MessageQueue P2MessageQueue P1socket P2socket

P1FIFO: P1FIFO.c
	gcc P1FIFO.c -o P1FIFO

P2FIFO: P2FIFO.c
	gcc P2FIFO.c -o P2FIFO

P1MessageQueue: P1MessageQueue.c
	gcc P1MessageQueue.c -o P1MessageQueue

P2MessageQueue: P2MessageQueue.c
	gcc P2MessageQueue.c -o P2MessageQueue

P1socket: P1socket.c
	gcc P1socket.c -o P1socket

P2socket: P2socket.c
	gcc P2socket.c -o P2socket

clean: 
	rm P1FIFO P2FIFO P1MessageQueue P2MessageQueue P1socket P2socket