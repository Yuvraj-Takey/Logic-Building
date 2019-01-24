/*
 * program with a function deletes2 (s1, s2). This function deletes each character in string s1 which matches any character in string s2
 *
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#define MAXCHAR		80
#define TRUE		1
#define FALSE		0

/***********************************************************************************
	Function			: deletes()
	Description			: This function removes each character from first string, which matches with second string
	Input				: char*, char* 
	Output				: nothing

	@Author : Yuvraj Takey
*/

void deletes(char *c_s1, char *c_s2)
{
	int i_index = 0, j_index = 0;
	char *c_Result = NULL, *c_Temp = NULL, flag;
	
	//allocate memory dynamically
	c_Result = (char*)malloc(MAXCHAR*sizeof(char));
	
	// preserve the pointer
	c_Temp = c_Result;
	
	// iterate the second string till end
	for(i_index = 0; (c_s1[i_index]) != '\0'; i_index++)
	{
		flag = TRUE;
		
		// iterate the first string
		for(j_index = 0; (c_s2[j_index]) != '\0'; j_index++)
		{
			// check for equal character in first string
			if(c_s1[i_index] == c_s2[j_index])
			{
				flag = FALSE;
			}
		}
		
		// check condition
		if(flag == TRUE)
		{
			// if character not matched then insert it into result array
			*c_Result = c_s1[i_index];
			
			// increment the address
			c_Result++;
		}
	}
	
	// printing output
	printf("Your String : %s\n",c_Temp);
	
	// free dynamically allocated memory also initialize pointer variable to NULL
	free(c_Temp);
	c_Result = NULL;
	c_Temp = NULL;

	return;
}

int main()
{
	char c_str1[MAXCHAR] = {'\0'}, c_str2[MAXCHAR] = {'\0'};
	
	// accept the input from user
	printf("Kindly enter first string\n");
	scanf("%[^'\n']s",c_str1);
	printf("Kindly enter second string\n");
	scanf(" %[^'\n']s",c_str2);
	
	//passing base address of arrays as argument to the function
	deletes(c_str1,c_str2);
		
	return 0;
}
