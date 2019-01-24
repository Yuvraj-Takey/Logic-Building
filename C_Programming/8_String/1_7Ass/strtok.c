/*
 * a Program to implement strtok library function.
 *
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#define MAXCHAR		80

/***********************************************************************************
	Function			: str_Token()
	Description			: This function tokenize the given string
	Input				: char*, char
	Output				: char*

	@Author : Yuvraj Takey
*/
char* str_Token(char* str, char delimit)
{
	static char token[MAXCHAR];
	int i_index = 0;
	static int i_offset = 0;
	
	// if string ends then send NULL (as string complition status or character not present in string)
	if(str[i_offset] == '\0')
	{
		// make counter reset for future purpose
		i_offset = 0;
		return NULL;
	}
	
	// clean local buffer
	memset(token,0,MAXCHAR);
	
	// iterate till string end
	while(str[i_offset] != '\0')
	{
		// if delimit matches
		if(str[i_offset] == delimit)
		{
			// if there are more than delimit found in string then iterate till all delimit
			while(str[i_offset] == delimit)
			{
				////// skip all delimits
				i_offset++;
			}
			
			// break the loop and return the current tokenized string
			break;
		}
	
		// copy the content into local buffer	
		token[i_index] = str[i_offset];
		
		// increment pointer address
		i_offset++;
		
		// increment the i_index variable
		i_index++;
	}
	
	return (token);
}

int main()
{
	char c_String[MAXCHAR] = {'\0'}, c_delimit = ' ', *token = NULL;
	
	printf("Kindly enter any string\n");
	scanf("%[^'\n']s",c_String);
	
	printf("Kindly enter the delimiter for tokenization\n");
	scanf(" %c",&c_delimit);
	
	// passing arguments to the function
	while((token = str_Token(c_String, c_delimit)) != NULL)
	{
		printf("--->\t %s\n",token);		
	}
	
	return 0;
}
