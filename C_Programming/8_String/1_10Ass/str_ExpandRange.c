/*
 * a function expand (s1, s2) which expands shorthand notations of s1 like a-d into abcd and 0-9 to 0123456789 in s2.
 * For example if the string in s1 is 0123a-e1-4 then s1 is expanded in s2 to 0123abcde1234.
 *
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR		80

/***********************************************************************************
	Function			: expand()
	Description			: This function expands the range which is guven by user in string
	Input				: char*, char*
	Output				: nothing

	@Author : Yuvraj Takey
*/
void expand(char *s1, char *s2)
{
	char c_index = ' ';
	int i_index = 0;
	short s_limitS2 = 0;
	
	// filter for string checking
	if((*s1 == '-') || (s1 == NULL))
	{
		printf("[SORRY] : invalid input\n");
		return ;
	}
	
	for(i_index = 0; s1[i_index] != '\0'; i_index++)
	{
		// expandation logic
		if(s1[i_index] == '-')
		{
		
			// come one step back
			s2--;
						
			for(c_index = s1[i_index-1]; c_index <= s1[i_index+1]; c_index++)
			{	
				// assign the elememt
				*s2 = c_index;
				
				// go one step forword
				s2++;
				
				// increment limit for string 2
				s_limitS2++;
				
				// check limit for string 2
				if(s_limitS2 > ((MAXCHAR * 2)-10))
				{
					// terminate string 2
					*s2 = '\0';
					
					// set the flag for limit exceeded
					s_limitS2 = -1;
					break;
				}
			}
			
			// increment by 1 more time
			i_index++;
		}
		else
		{
			// initialise the character from s1 to s2
			*s2 = s1[i_index];
			
			// increment the address
			s2++;
			
			// increment limit for string 2
			s_limitS2++;
			
			// check limit for string 2
			if(s_limitS2 > ((MAXCHAR * 2)-10))
			{
				// make s2 as terminated string
				*s2 = '\0';
				
				// set flag for termination of the program
				s_limitS2 = -1;
			}
		}
		
		// if limit exceeded then stop the loop and return
		if(s_limitS2 == -1)
		{
			printf("[SORRY] : limit exceeded for string 2\n\n");
			break;
		}		
	}
	
	return ;
}

int main()
{
	char c_arr1[MAXCHAR] = {'\0'};
	char *c_arr2 = NULL;
	
	// accepting the input
	printf("Kindly enter string (include : Ranges like- (0-9), (a-z), (A-Z))\n");
	scanf("%[^'\n']s",c_arr1);
	
	// memory allocation dynamically for result of expand
	c_arr2 = (char*)malloc((MAXCHAR * 2) * sizeof(char));
	
	// passing argument as address to function
	expand(c_arr1, c_arr2);
	
	// printing the result
	printf("Your string is :\n%s\n",c_arr2);
	
	// free the dynamic memory	
	free(c_arr2);
	c_arr2 = NULL;
	
	return 0;
}
