#include<stdio.h>
main()
{
	int a,b,c;
	printf("Please input 2 numbers:\n");
	scanf("%d,%d",&a,&b);
	c=max(a,b);
	printf("The max number is %d",c);
}

int max(x,y)
int x,y;
{
	int z;
	if(x>y) z=x;
	else z=y;
	return(z);
}
