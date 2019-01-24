/*
 * a function ``replace'' which takes a pointer to a string as a parameter, which replaces all spaces in that string by minus signs,
 * and delivers the number of spaces it replaced.
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/***********************************************************************************
	Function			: replace()
	Description			: This function replaces space with minus symbol
	Input				: int, 
	Output				: int

	@Author : Yuvraj Takey
*/

int replace(char *str)
{
	// allocate memory dynamically
	char *strDyn = (char*)malloc(strlen(str)*sizeof(char));
	int iCount = 0, index = 0;
	
	// iterate loop till end of the string
	for(index = 0; str[index] != '\0'; index++)
	{
		// check for spaces
		if(str[index] == ' ')
		{
			// increase count and replace spaces with minus
			iCount++;
			strDyn[index] = '-';
		}
		else
		{
			// copy other
			strDyn[index] = str[index];
		}
	}
	
	// print result
	printf("%s\n",strDyn);
	
	// free the memory
	free(strDyn);
	return iCount;
}

int main()
{
	int n = 0;
	char *cat = "The cat sat";
	
	// calling to the function
	n = replace(cat);
	
	//printing result
	printf("The number of spaces which replaced : %d\n\n",n);
	return 0;
}
