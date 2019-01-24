/*
 * Write a program to print all the prime numbers in the first N numbers.
 *
 *	=> A prime number is a whole number greater than 1 whose only factors are 1 and itself
 *		ex : 2, 3, 5, 7, 11, 13, 17, 19, 23 
 *
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#define PRIME_LIMIT	2
#define SUCCESS		0

/***********************************************************************************
	Function			: prime_Num()
	Description			: This function finds all prime number till the given number
	Input				: int
	Output				: nothing

	@Author : Yuvraj Takey
*/

void prime_Num(int i_value)
{
	int index = 0;
	char c_count = 0;
	
	// traverse the loop till the given number
	for(index = 1; index <= i_value; index++)
	{
		// checking wheather prime or not
		if((i_value % index) == SUCCESS)
		{
			c_count++;	
		}
	}
	
	// checking loop termination	
	if(c_count == PRIME_LIMIT)
	{
		printf("[DONE_] : The Number %d is prime number\n", i_value);
	}
	else
	{
		printf("[SORRY] : The Number %d is not prime number\n", i_value);
	}
	
	return ;
}

int main()
{
	int i_value = 0;
	
	printf("Enter an element to get the list of prime numbers\n");
	scanf("%d",&i_value);

	// passing the number to the function (call by value)	
	prime_Num(i_value);
	
	return 0;
}
