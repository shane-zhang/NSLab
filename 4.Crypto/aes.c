#include <openssl/aes.h>

int main(void)
{
	AES_KEY key;
	int ERROR=10,i;
	char buffer[512]={'\0'};
	char buffer2[512]={'\0'};
	printf("%d,%d\n",ERROR,key.rounds);
	ERROR = AES_set_encrypt_key("This is a password",128,
	&key);
	printf("%d,%d\n",ERROR,key.rounds);
	AES_encrypt("Xiao@09055136",buffer,&key);
	printf("%s\n%d\n",buffer,strlen(buffer));
	for(i=0;i<strlen(buffer);i++)
	{
		printf("%hhx\n",buffer[i]);
	}
	AES_set_decrypt_key("This is a password",128,
	&key);
	AES_decrypt(buffer,buffer2,&key);
	printf("\n%s\n",buffer2);
	return 0;
}