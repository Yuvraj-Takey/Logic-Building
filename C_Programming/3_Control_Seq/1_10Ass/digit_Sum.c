/*
 * Write a program to find the sum of digits of a given number
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>

/***********************************************************************************
	Function			: digit_Sum()
	Description			: This function calculates the sum of digits of a given number
	Input				: int
	Output				: int

	@Author : Yuvraj Takey
*/

int digit_Sum(int i_Number)
{
	int i_digit = 0, i_count = 0;
	
	while(i_Number != 0)
	{
		// get the digit from number
		i_digit = i_Number % 10;
		
		// make addition of digits
		i_count = i_count + i_digit;
		
		// reduce the number
		i_Number = i_Number / 10;
	}
	
	// if the count becomes again number (by calculation)
	if(i_count > 9)
	{
		// recursive call to get the exact digit
		i_count = digit_Sum(i_count);
	}
	
	return i_count;
}

int main()
{
	int i_value = 0, i_result = 0;
	
	printf("Enter any number\n");
	scanf("%d",&i_value);
		
	// value passing to the function
	i_result = digit_Sum(i_value);
	
	printf("[DONE_] : The sum of digits of a given number is %d\n",i_result);
	
	return 0;
}
