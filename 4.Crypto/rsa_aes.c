#include <openssl/aes.h>
#include <openssl/rsa.h>

int main(void)
{
	RSA *r = RSA_generate_key(1024, RSA_F4, NULL, NULL);
	const char *AESKey  = "Thisisapassword!";
	AES_KEY key;
	char *Plain  = "Xiao09055136CS96";
	unsigned char RSA_AES[256]={'\0'};
	unsigned char AES_Plain[256]={'\0'};
	unsigned char buffer[256]={'\0'};
	RSA_print_fp(stdout,r,0);
	int n,i;
	RSA_public_encrypt(RSA_size(r),AESKey,RSA_AES,r,RSA_NO_PADDING);
	printf("The encrypted AES Key:%s\n",RSA_AES);
	for(i=0;i<strlen(RSA_AES);i++)
	{
		printf("%02x",(unsigned char)RSA_AES[i]);
	}
	printf("\n");
	AES_set_encrypt_key(AESKey,128,
	&key);
	AES_ecb_encrypt(Plain,AES_Plain,&key,AES_ENCRYPT);
	
	printf("The encrypted Pliantext:%s\n",AES_Plain);
	for(i=0;i<strlen(AES_Plain);i++)
	{
		printf("%02x",(unsigned char)AES_Plain[i]);
	}
	printf("\n");
	
	RSA_private_decrypt(RSA_size(r),RSA_AES,buffer,r,RSA_NO_PADDING);
	printf("The decrypted AES key:%s\n",buffer);
	for(i=0;i<strlen(buffer);i++)
	{
		printf("%02x",(unsigned char)buffer[i]);
	}
	printf("\n");
	
	AES_set_decrypt_key(buffer,128,
	&key);
	AES_ecb_encrypt(AES_Plain,buffer,&key,AES_DECRYPT);
	printf("The decrypted Plaintext:%s\n",buffer);
	RSA_free(r);
	return 0;
}