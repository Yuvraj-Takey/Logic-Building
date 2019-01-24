/*
 * . If i is 20 or j is 20, display as “Atleast one variable is having 20” otherwise display “Both variables are not having 20”. 
 * If i is less than or equal to 40 and j is less than or equal to 40, It should display “Both are less than or equal to 40” otherwise,
 * it should display as “Both are not less than or equal to 40”.
 * Implement this using if-else statement as well as with conditional operator.
 *
 * @Author - Yuvraj Takey
*/

#include <stdio.h>

int main()
{	
	// variable creation
	int i_value = 0, j_value = 0;
	
	// accept the values
	printf("Enter two variable\n");
	scanf("%d%d",&i_value,&j_value);
	
	// using IF-ELSE statement
	if((i_value == 20) || (j_value == 20))
	{
		printf("Atleast one variable is having 20\n");
	}
	else
	{
		printf("Both variables are not having 20\n");
	}
	
	// using conditional operator
	((i_value <= 40) && (j_value <= 40)) ? printf("Both are less than or equal to 40\n") : printf("Both are not less than or equal to 40\n") ;
	

	return 0;
}
