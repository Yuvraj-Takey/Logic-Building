/*
 *	a program to count the number of ‘e’ in the following array of pointer to string
 *
 *	char * s [ ] = {
 *	“we will teach you how to “ ;
 *	“Move a mountain “ ;
 *	“Level a building “ ;
 *	“Erase the past “;
 *	“Make a million “ ;}.
 *
 *	@Author - Yuvraj Takey
*/

#include<stdio.h>

int main()
{
	char *s[] = {
			"We will teach you how to",	// s+0
			"Move a mountain",		// s+1
			"Level a building",		// s+2
			"Erase the past",		// s+3
			"Make a million"		// s+4
			};
	int i_count = 0;
	
	// iterate the loop till all strings
	for(int i = 0; i < 5; i++)
	{	
		// Take each string traverse
		while(*(*(s+i)) != '\0')
		{
			// compare each character of that string with 'e'
			if((*(*(s+i)) == 'e') || (*(*(s+i)) == 'E'))
			{
				// increment the counter
				i_count++;
			}
			
			// increment the address of character
			(*(s+i))++;
		}
	}
	
	printf("[DONE_] : Number of e's is %d\n",i_count);
	return 0;
}
