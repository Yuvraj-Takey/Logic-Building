/*
 * Write a program to print out all rotations of a string typed in.
 * For eg:if the input is “Space”, the output should be: space paces acesp cespa espac
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define MAXCHAR	80
 
 /***********************************************************************************
	Function			: str_Rotate()
	Description			: This function rotates the given string as one by one character
	Input				: char*
	Output				: nothing

	@Author : Yuvraj Takey
*/

void str_Rotate(char *str)
{
	int i_index = 0, j_index = 0;
	char c_Preserv = ' ';
	
	// iterate loop till number of possibilities
	for(i_index = 0; str[i_index] != '\0'; i_index++)
	{
		// printing string on screen
		printf("----> %s\n",str);
		
		// preserve first character in temporary variable
		c_Preserv = str[0];
		
		// iterate till all character not shifted to left
		for(j_index = 0; str[j_index+1] != '\0'; j_index++)
		{
			// swaping character inplace
			str[j_index] = str[j_index+1];
		}
		
		// put the preserved character at the end of string
		str[j_index] = c_Preserv;
	}
	
	return;
}
 
 int main()
 {
 	char c_Arr[MAXCHAR] = {'\0'};
 	
 	// accept input
 	printf("Kindly enter any string\n");
 	scanf("%[^'\n']s",c_Arr);
 
 	// calling function using call by address	
 	str_Rotate(c_Arr);
 	
	return 0;
 }
