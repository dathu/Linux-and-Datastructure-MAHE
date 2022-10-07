#include<unistd.h>
int main()
{
write(1,"hello\n",60); //the bytes to be printed (third parameter) are more than the data specified in 2nd parameter
}
