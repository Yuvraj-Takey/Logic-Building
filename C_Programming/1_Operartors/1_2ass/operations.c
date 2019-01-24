#include <stdio.h>

/*
	Function		: main
	Discription		: add two operands and store the result in one of the operand using addition assignment operator.
	input			: int, int
	output			: int
	
	@Author : Yuvraj Takey
*/
int main()
{
	int i_Xinput = 0, i_Yinput = 0;

	printf("Enter any 2 whole numbers\n");
	scanf("%d%d",&i_Xinput,&i_Yinput);
	
	i_Xinput += i_Yinput;
	
	// a+=b	=> a = a+b	

	printf("done_ : The addition of given whole number is %d\n",i_Xinput);
	
	return 0;
}
