#include<stdio.h>
#include<string.h>
int main（int argc,char **argv)
{
	char buf[10];
	strcpy(buf,argv[1]);
	printf("buf's 0x%8x\n",&buf);
	return 0;
}
