/*
 *
 *print ASCII values of upper case and lower case alphabets and digits (A-Z, a-z and 0-9).
 *
 *	@Author	- Yuvraj Takey
*/

#include <stdio.h>

int main()
{
	int index = 0;
	printf("Here are the list of ASCII values\n");
	
	// iterate the loop till the 1 byte range
	for(index = 0; index < 256; index++)
	{
		// filters
		if((index >= 'A') && (index <= 'Z'))
		{
			printf("ASCII value : %d\t Character : %c\n",index,index);
		}
		else if((index >= 'a') && (index <= 'z'))
		{
			printf("ASCII value : %d\t Character : %c\n",index,index);
		}
		else if((index >= '0') && (index <= '9'))
		{
			printf("ASCII value : %d\t Character : %c\n",index,index);
		}
	}
	
	return 0;
}
