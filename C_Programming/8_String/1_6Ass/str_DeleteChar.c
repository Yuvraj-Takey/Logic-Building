/*
 * a C program with a function delete (s1, c). This function deletes each character in s1 which matches character c.
 *
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdio_ext.h>
 #define MAXCHAR	80

/***********************************************************************************
	Function			: str_Delete()
	Description			: This function deletes the given character from given string
	Input				: char*, char
	Output				: nothing

	@Author : Yuvraj Takey
*/ 
void str_Delete(char c_arr[MAXCHAR], char c_DelChar)
{
	int index = 0;
	
	// iterate loop till end of string
	while((c_arr[index]) != '\0')
	{
		// check for each character with deleting character
		if((c_arr[index]) == c_DelChar)
		{
			// delete the character by replacing white space
			c_arr[index] = ' ';
		}
		else if(c_arr[index] == ' ')
		{
			// for keeping spaces between two words
			c_arr[index] = '\n';
		}
		
		// increment pointer
		index++;
	}
	
	for(index = 0; c_arr[index] != '\0'; index++)
	{
		if(c_arr[index] == ' ')
		{
			for(int j = index+1; c_arr[j] != '\0'; j++)
			{
				// skip that spaces between two words
				if(c_arr[j] == '\n')
				{
					c_arr[j] = ' ';
					break;
				}
				else if(c_arr[j] == ' ')
				{
					continue;
				}
				else
				{
					c_arr[index] = c_arr[j];
					c_arr[j] = ' ';
					break;
				}
			}
		}
	}
	
	
	return ;
}
 
int main()
{
	char c_arr[MAXCHAR] = {'\0'}, c_CharDel = ' ';
	
	printf("Kindly enter any string\n");
	scanf("%[^'\n']s",c_arr);

	// flush buffer
	__fpurge(stdin);
		
	printf("Kindly enter the character that you want to delete from above string\n");
	scanf("%c",&c_CharDel);
	
	// calling function
	str_Delete(c_arr, c_CharDel);

	printf("%s\n",c_arr);

	return 0;
}
