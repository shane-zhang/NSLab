#include<stdio.h>

void fun()
{
	printf("This programme has been hacked by zx0319@gmail.com\n");
}

int main(int argc,char **argv)
{
	char buf[10];
	strcpy(buf,argv[1]);
	printf("buf's 0x%8x\n",&buf);
	printf("fun is 0x%8x\n",fun);
	return 0;
}
