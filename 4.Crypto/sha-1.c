#include <openssl/sha.h>

int main(void)
{
	SHA_CTX c;
	unsigned char buffer[20]={'\0'};
	int i;
	SHA1_Init(&c);
	SHA1_Update(&c,"Xiao09055136CS96",16);
	SHA1_Final(buffer,&c);
	for(i=0;i<20;i++)
	{
		printf("%02x",buffer[i]);
	}
	printf("\n");
	return 0;
}