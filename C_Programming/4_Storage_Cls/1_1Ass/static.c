#include "header.h"

static int b = 9;

void sfun()
{
	static int s_no = 0;
	
	s_no++;
	
	printf("The value of static increasing %d\n",s_no);
}

int main(void)
{
	int var = 10;
	printf("\n Variable is %d\n",var);
	
	sfun();
	sfun();
	sfun();
	
	printf("\n A value is %d\n",a);
	printf("\n B value is %d\n",b);
	return 0;
}
