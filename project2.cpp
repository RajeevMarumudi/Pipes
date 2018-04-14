#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	FILE *a;
	int n,p;
	char buff[50];
	a=popen(buff,sizeof(char),50,a);
	write(1,buff,50);
	pipe(a);
	p=fork();
	if(p==0)
	{
		close(a[0]);
		write(1,"Enter anything",13);
		n=read(0,buff,30);
		write(a[1],buff,n);
	}
	else
	{
		
	}
}
