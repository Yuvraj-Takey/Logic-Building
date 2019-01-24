/*
 *
 * Write a Program to find if a given number is Armstrong number.
 * Hint: (153 = 1^3 + 5^3 + 3^3)
 *
 *	In recreational number theory,
 *	a narcissistic number is a number that is the sum of its own digits each raised to the power of the number of digits.
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>

/***********************************************************************************
	Function			: count_Digit()
	Description			: This function will count the digits from given number
	Input				: int
	Output				: int

	@Author : Yuvraj Takey
*/
int count_Digit(int i_Number)
{
	int i_cnt = 0;
	
	//iterate till the number becomes 0
	while(i_Number != 0)
	{
		// decrease the number by 1
		i_Number = i_Number/10;
		
		// count the digits
		i_cnt++;
	}
	
	return i_cnt;
}

/***********************************************************************************
	Function			: powerof_Num()
	Description			: This function calculate the power of given number
	Input				: int, int
	Output				: int

	@Author : Yuvraj Takey
*/
int powerof_Num(int i_digit,int i_Number_len)
{
	int index = 0, i_result = 1;

	// iterate till the powerof_value (i.e 2^3  => 3 times)	
	for(index = 0; index < i_Number_len; index++)
	{
		// make multiplication
		i_result = i_result * i_digit;
	}
	
	return i_result;
}

/***********************************************************************************
	Function			: armstrong_Num()
	Description			: This function calculate the armstrong logic
	Input				: int
	Output				: int

	@Author : Yuvraj Takey
*/
int armstrong_Num(int i_Number)
{
	int i_result = 0, i_digit = 0, i_Number_len = 0;
	
	// get the number of digits of given number
	i_Number_len = count_Digit(i_Number);
	
	// iterate till the i_value becomes 0
	while (i_Number != 0)
	{
		// get the digit from number
		i_digit = i_Number % 10;
		
		// Armstrong logic
		i_result = i_result + powerof_Num(i_digit,i_Number_len);
		
		// reduce the accepted number
		i_Number = i_Number/10;
	}
	
	return i_result;
}

int main()
{
	int i_value = 0, i_result = 0;
	
	printf("Enter any number for checking Armstrong\n");
	scanf("%d",&i_value);
	
	// passing the value to the function	
	i_result = armstrong_Num(i_value);
	
	if(i_result == i_value)
	{
		printf("\n[DONE_] : The number is Armstrong number\n");
	}
	else
	{
		printf("\n[DONE_] : The number is not Armstrong number\n");
	}
	
	return 0;
}
