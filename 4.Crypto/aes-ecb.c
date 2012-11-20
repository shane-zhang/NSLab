#include <openssl/aes.h>

int main(void)
{
	AES_KEY key;
	int ERROR=10,i;
	char buffer[512]={'\0'};
	char buffer2[512]={'\0'};
	printf("%d,%d\n",ERROR,key.rounds);
	ERROR = AES_set_encrypt_key("Thisisapassword!",128,
	&key);
	printf("%d,%d\n",ERROR,key.rounds);
	AES_ecb_encrypt("Xiao09055136CS96",buffer,&key,AES_ENCRYPT);
	printf("%s\n%d\n",buffer,strlen(buffer));
	for(i=0;i<strlen(buffer);i++)
	{
		printf("%02x",(unsigned char)buffer[i]);
	}
	AES_set_decrypt_key("Thisisapassword!",128,
	&key);
	AES_ecb_encrypt(buffer,buffer2,&key,AES_DECRYPT);
	printf("\n%s\n",buffer2);
	AES_set_decrypt_key("This is a pass",128,
	&key);
	AES_ecb_encrypt(buffer,buffer2,&key,AES_DECRYPT);
	printf("\n%s\n",buffer2);
	return 0;
}