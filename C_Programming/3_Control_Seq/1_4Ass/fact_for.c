/*
 *
 * Develop a C program to find factorial of a number N using for loop
 *
 * @Author - Yuvraj Takey
*/

#include <stdio.h>

int main()
{
	int i_value = 0, index = 0, i_result = 1;
	
	printf("Enter the number for finding factorial\n");
	scanf("%d",&i_value);
	
	// traverse the loop till that number
	for(index = 1; index <= i_value; index++)
	{
		// make factorial calculation
		i_result = i_result * index;
	}
	
	printf("The factorial of a given number is : %d\n",i_result);
	
	return 0;
}
