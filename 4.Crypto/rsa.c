#include <openssl/rsa.h>

int main(void)
{
	RSA *r;
	r = RSA_generate_key(1024, RSA_F4, NULL, NULL);
	char buffer[256]={'\0'};
	char buffer2[256]={'\0'};
	RSA_print_fp(stdout,r,0);
	int n,i;
	RSA_public_encrypt(RSA_size(r),"Xiao@09055136CS96",buffer,r,RSA_NO_PADDING);
	printf("%s\n",buffer);
	for(i=0;i<strlen(buffer);i++)
	{
		printf("%02x",(unsigned char)buffer[i]);
	}
	RSA_private_decrypt(RSA_size(r),buffer,buffer2,r,RSA_NO_PADDING);
	printf("\n%s\n",buffer2);
	
	RSA_private_encrypt(RSA_size(r),"Xiao@09055136CS96",buffer,r,RSA_NO_PADDING);
	printf("%s\n",buffer);
	for(i=0;i<strlen(buffer);i++)
	{
		printf("%02x",(unsigned char)buffer[i]);
	}
	RSA_public_decrypt(RSA_size(r),buffer,buffer2,r,RSA_NO_PADDING);
	printf("\n%s\n",buffer2);
	RSA_free(r);
	return 0;
}