/*
 *  accepts character type data item from user. In case if user typed
 *	‘A’ or ‘a’, it should display A for Apple
 *	‘B’ or ‘b’, it should display B for Bat
 *	‘D’ or ‘d’, it should display D for Dog
 *	‘F’ or ‘f’, it should display F for Fan
 *  Instead of the above 4 characters, if user types any other character, it should display “Character is not in the
 *  range”. Implement this using if-else statement and switch statement.
 *
 *	@Author - Yuvraj Takey
 *
*/

#include <stdio.h>

int main()
{
	char c_value = ' ';
	
	printf("Enter the character\n");
	scanf("%c",&c_value);
	
	// conditional statement
	if(c_value == 'a')
	{
		printf("a for apple\n");
	}
	else if(c_value == 'b')
	{
		printf("b for bat\n");
	}
	else if(c_value == 'd')
	{
		printf("d for dog\n");
	}
	else if(c_value == 'f')
	{
		printf("f for fan\n");
	}
	else
	{
		// Switch statement
		switch(c_value)
		{
			case 'A':
				printf("A for APPLE\n");
				break;			
			case 'B':
				printf("B for BAT\n");
				break;
			
			case 'D':
				printf("D for DOG\n");
				break;
			
			case 'F':
				printf("F for FAN\n");
				break;
			
			default :
				printf("Character is not in the range\n");
		}
	}
	return 0;
}
