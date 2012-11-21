#include <openssl/sha.h>
#include <openssl/rsa.h>

int main(void)
{
	RSA *r = RSA_generate_key(1024, RSA_F4, NULL, NULL);
	char *Plain  = "Xiao09055136";
/*	
	const unsigned char sha1[20] = {
		0xf2, 0x6e, 0x6e, 0x75, 0x5b, 0xef, 0xf3, 0xb9, 0x2b, 0x9f,
		0xc0, 0x51, 0x17, 0x16, 0xbf, 0xc8, 0xc3, 0x64, 0x64, 0x41
		0x6d, 0x33, 0xf9, 0x40, 0x75, 0x5b, 0x4e, 0xc5, 0x90, 0x35,
		0x48, 0xab, 0x75, 0x02, 0x09, 0x76, 0x9a, 0xb4, 0x7d, 0x6b
	    };
*/
	unsigned char SHA_1_Plain[128]={'\0'};
	unsigned char RSA_SIG[128]={'\0'};
	unsigned char buffer[256]={'\0'};
	char *temp;
	RSA_print_fp(stdout,r,0);
	int n,i;
	unsigned long e=0;
	
	
	SHA_CTX c;
	SHA1_Init(&c);
	SHA1_Update(&c,Plain,16);
	SHA1_Final(SHA_1_Plain,&c);
	printf("The plaintext:%s\n and the message degist:%s\n",Plain,SHA_1_Plain);
	for(i=0;i<strlen(SHA_1_Plain);i++)
	{
		printf(",0x%02x",SHA_1_Plain[i]);
	}
	printf("%d\n",strlen(SHA_1_Plain));
	RSA_private_encrypt(RSA_size(r),SHA_1_Plain,RSA_SIG,r,RSA_NO_PADDING);
	printf("The signature information:%s\n",RSA_SIG);
	for(i=0;i<strlen(RSA_SIG);i++)
	{
		printf("%02x",(unsigned char)RSA_SIG[i]);
	}
	printf("\n");
	
/*
	e =ERR_get_error();
	printf("%d",e);
	ERR_error_string(e,buffer);
	puts(buffer);
*/
	RSA_public_decrypt(RSA_size(r),RSA_SIG,buffer,r,RSA_NO_PADDING);
	printf("The decrypted sigenature:%s\n",buffer);
	for(i=0;i<strlen(buffer);i++)
	{
		printf("%02x",(unsigned char)buffer[i]);
	}
	printf("\n");
	RSA_free(r);
	return 0;
}