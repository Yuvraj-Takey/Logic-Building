/*
 * a program to read n number of strings and display them on the screen. Use array of pointers and dynamic memory allocation techniques.
 *
 *	@Author - Yuvraj Takey
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define MAXCHAR		80

int main()
{
	char **c_strP = NULL, ch_flag = ' ';
	int i_Num = 0, index = 0;
	
	printf("Enter number of strings that want to store\n");
	scanf("%d",&i_Num);
	
	// allocating memory for rows
	c_strP = (char**)malloc(i_Num*sizeof(char*));
	if(c_strP == NULL)
	{
		printf("[SORRY] : Memory allocation failed\n");
		return (-1);
	}
	
	printf("Kindly enter your string one by one\n");
	
	// iterate loop till number of rows
	for(index = 0; index < i_Num; index++)
	{
		// allocating memory for columns
		c_strP[index] = (char*)malloc(MAXCHAR*sizeof(char));
		if(c_strP == NULL)
		{
			printf("[SORRY] : Memory allocation failed\n");
			break;
		}
		
		// flush the buffer
		__fpurge(stdin);
		
		// read strings one by one
		scanf("%[^'\n']s",c_strP[index]);
	}
	
	// user choice
	printf("Do you want to display all strings ? (y/n)_");
	scanf(" %c",&ch_flag);

	// checking display flag	
	if((ch_flag == 'y') || (ch_flag == 'Y'))
	{
		// printing whole accepted strings on screen
		for(index = 0; index < i_Num; index++)
		{
			printf("%s\n",c_strP[index]);
		}
	}
	
	return 0;
}
