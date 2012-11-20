#include <openssl/aes.h>

int main(void)
{
	AES_KEY key;
	int ERROR=10,i;
	char buffer[512]={'\0'};
	char buffer2[512]={'\0'};
	unsigned char key16[16] = "0123456789abcdef";
	printf("%d,%d\n",ERROR,key.rounds);
	ERROR = AES_set_encrypt_key("This is a password",128,
	&key);
	printf("%d,%d\n",ERROR,key.rounds);
	AES_cbc_encrypt("Xiao@09055136",buffer,16,&key,key16,AES_ENCRYPT);
	printf("%s\n%d\n",buffer,strlen(buffer));
	for(i=0;i<strlen(buffer);i++)
	{
		printf("%hhx\n",buffer[i]);
	}
	AES_set_decrypt_key("This is a password",128,
	&key);
	AES_cbc_encrypt(buffer,buffer2,16,&key,key16,AES_DECRYPT);
	printf("\n%s\n",buffer2);
	return 0;
}