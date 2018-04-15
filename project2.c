#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
main()
{
int fd[2],n,f1,f2,n1;
char buff[50],buff1[50];
pid_t f;
pipe(fd);
f=fork();
if(f==0)
{
close(fd[0]);
f1=open("rajeev.txt",O_RDONLY,0777);
n=read(f1,buff,50);
write(fd[1],buff,n);
}
else if(f>0)
{
wait();
close(fd[1]);
n1=read(fd[0],buff1,50);
close(fd[0]);
f2=open("copyfile.txt",O_CREAT|O_RDWR,0777);
write(f2,buff1,n1);
}
}
