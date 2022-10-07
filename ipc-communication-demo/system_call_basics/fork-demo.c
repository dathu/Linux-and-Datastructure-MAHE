#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t p;
printf("before fork\n");
p=fork();
if(p==0)
{
printf("My parent's id is %d\n",getppid());
printf("I am child having id %d\n",getpid());
}
else{
printf("My child's id is %d\n",p);
printf("I am parent having id %d\n",getpid());
}
printf("Welcome to MSIS, MAHE, Manipal\n");
printf("-----------------------------------------\n");
}
