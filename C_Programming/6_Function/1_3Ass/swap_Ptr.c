/*
 * Write a function to swap contents of two variables using functions and pointer variables.
 *
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>

 /***********************************************************************************
	Function			: swap_P()
	Description			: This function swaps the given number
	Input				: int*, int*
	Output				: nothing

	@Author : Yuvraj Takey
*/
void swap_P(int *ptr1, int *ptr2)
{
	int temp = 0;

	// swapping logic
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

	return;
}

int main()
{
	int iVal_A =0, iVal_B = 0;

	// accept input
	printf("Kindly enter the value of 'a'\n");
	scanf("%d",&iVal_A);
	printf("Kindly enter the value of 'b'\n");
	scanf("%d",&iVal_B);

	printf("Swapping..\n");

	// function call using call by address
	swap_P(&iVal_A,&iVal_B);

	// printing the result
	printf("The value of 'a' is %d\nThe value of 'b' is %d\n", iVal_A, iVal_B);

	return 0;
}