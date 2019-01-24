#include <stdio.h>

/*
	Function		: Add
	Discription		: Provide addition of given number
	input			: int, int
	output			: int
	
	@Author : Yuvraj Takey
*/

void Add(int i_Num1, int i_Num2)
{
	if(i_Num1 < 0 || i_Num2 < 0)
	{
		printf("sorry : Invalid Number\n");
		return;
	}

	int i_Result = 0;
	
	i_Result = i_Num1 + i_Num2;

	printf("done_ : The addition of given number is %d\n",i_Result);

	return;
}

/*
	Function		: Sub
	Discription		: Provide substraction of given number
	input			: int, int
	output			: int
	
	@Author : Yuvraj Takey
*/
void Sub(int i_Num1, int i_Num2)
{
	if(i_Num1 < 0 || i_Num2 < 0)
	{
		printf("sorry : Invalid Number\n");
		return;
	}

	int i_Result = 0;
	
	i_Result = i_Num1 - i_Num2;

	printf("done_ : The substraction of given number is %d\n",i_Result);

	return;
}


/*
	Function		: Mult
	Discription		: Provide multiplication of given number
	input			: int, int
	output			: int
	
	@Author : Yuvraj Takey
*/
void Mult(int i_Num1, int i_Num2)
{
	if(i_Num1 < 0 || i_Num2 < 0)
	{
		printf("sorry : Invalid Number\n");
		return;
	}

	int i_Result = 0;
	
	i_Result = i_Num1 * i_Num2;

	printf("done_ : The Multiplication of given number is %d\n",i_Result);

	return;
}

/*
	Function		: Div
	Discription		: Provide division of given number
	input			: int, int
	output			: float
	
	@Author : Yuvraj Takey
*/
void Div(int i_Num1, int i_Num2)
{
	if(i_Num1 < 0 || i_Num2 < 0)
	{
		printf("sorry : Invalid Number\n");
		return;
	}

	float f_Result;
	
	f_Result = ((float)i_Num1 / (float)i_Num2);

	printf("done_ : The division of given number is %.4f\n",f_Result);

	return;
}


/*
	Function		: Modulo
	Discription		: Provide modulo of given number
	input			: int, int
	output			: int
	
	@Author : Yuvraj Takey
*/
void Modulo(int i_Num1, int i_Num2)
{
	if(i_Num1 < 0 || i_Num2 < 0)
	{
		printf("sorry : Invalid Number\n");
		return;
	}

	int i_Result = 0;
	
	i_Result = (i_Num1 % i_Num2);

	printf("done_ : The modulo of given number is %d\n",i_Result);

	return;
}

int main()
{
	int i_Xinput = 0, i_Yinput = 0;

	printf("Enter any 2 whole numbers\n");
	scanf("%d%d",&i_Xinput,&i_Yinput);
	
	Add(i_Xinput,i_Yinput);			// for addition of input
	Sub(i_Xinput,i_Yinput);			// for substraction of input
	Mult(i_Xinput,i_Yinput);		// for multiplecation of input
	Div(i_Xinput,i_Yinput);			// for division of input
	Modulo(i_Xinput,i_Yinput);		// provide remainder of input
	
	return 0;
}
