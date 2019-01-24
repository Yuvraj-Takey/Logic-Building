#include <stdio.h>

/*
	Function		: main
	Discription		: find the maximum of 2 numbers using Conditional operator.
	input			: float, float
	output			: int
	
	@Author : Yuvraj Takey
*/
int main()
{
	float i_Xinput = 0.0f, i_Yinput = 0.0f;

	printf("Enter any 2 numbers\n");
	scanf("%f%f",&i_Xinput,&i_Yinput);

	(i_Xinput > i_Yinput) ? printf("done_ : The first number is maximum\n") : printf("done_ : The second number is maximum\n");	
	
	return 0;
}
