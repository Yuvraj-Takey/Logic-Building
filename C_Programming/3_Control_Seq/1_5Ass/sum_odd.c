/*
 * Develop a C program to find sum of all odd numbers upto N using while loop
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>

int  main()
{
	int i_value = 0, i_sum = 0;
	
	printf("Enter any number\n");
	scanf("%d",&i_value);
	
	// iterate till the value becomes 0
	while(i_value != 0)
	{
		// odd numbers filter
		if((i_value % 2) != 0)
		{
			i_sum = i_sum + i_value;
		}
		
		// the condition of while
		i_value--;
	}
	
	printf("The addition of all odd number is : %d\n", i_sum);

	return 0;
}
