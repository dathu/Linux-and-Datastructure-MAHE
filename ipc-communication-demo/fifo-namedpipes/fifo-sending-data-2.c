       #include<unistd.h>
        #include<stdio.h>
        #include<fcntl.h>
        int main()
        {
                    int res,n;
                    res=open("fifo1",O_WRONLY);
                    write(res,"Message",7);
                    printf("Sender Process %d sent the data\n",getpid());
        }
