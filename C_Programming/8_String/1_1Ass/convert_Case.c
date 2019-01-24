/*
 * a program to convert lower case string to upper case string and vice versa.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define MAXCHAR	80
 
 /***********************************************************************************
	Function			: change_Case()
	Description			: This function converts string case (upper-lower)
	Input				: char*
	Output				: nothing

	@Author : Yuvraj Takey
*/
void change_Case(char* str)
{
	// traverse the string till end
	while(*str != '\0')
	{
		// filter for changing character case
		if((*str >= 'a') && (*str <= 'z'))
		{
			// lower to upper
			*str = *str - 32;
		}
		else if((*str >= 'A') && (*str <= 'Z'))
		{
			// upper to lower
			*str = *str + 32;
		}
		
		// increment the pointer
		str++;
	}

	return ;
}
 
 int main()
 {
 	// array of character => string
 	char c_Text[MAXCHAR] = {'\0'};
 	 
 	printf("Enter a string (either lower case or upper case)\n");
 	scanf("%[^'\n']s",c_Text);
 
 	// passing the requested string to function	
 	change_Case(c_Text);
 	
 	printf("Your String : %s\n",c_Text);
 	
 	return 0;
 }
