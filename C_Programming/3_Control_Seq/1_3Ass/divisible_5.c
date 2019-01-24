/*
 * adds all numbers from 1 to N, except those which are divisible by 5. Implement this using for loop and continue statement
 *
 * @Author - Yuvraj Takey
*/

#include <stdio.h>

int main()
{
	int i_value = 0, index = 0, i_result = 0;
	printf("Enter any number \n");
	scanf("%d",&i_value);
	
	for(index = 1; index <= i_value; index++)
	{
		if((index % 5) == 0)
		{
			continue;
		}
		
		i_result = i_result + index;
	}
	
	printf("The addition is %d\n",i_result);
	return 0;
}
