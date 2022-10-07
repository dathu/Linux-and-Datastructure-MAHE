#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
FILE *rd;
char buffer[500];
rd=popen("ls","r"); //pipe opened in reading mode
fread(buffer, 1, 100, rd); //will read only 100 characters
printf("%s\n", buffer);
pclose(rd);
}
