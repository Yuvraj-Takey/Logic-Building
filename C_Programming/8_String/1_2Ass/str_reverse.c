/*
 *
 * a program to reverse a string using recursive functions
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define MAXCHAR	80
 
 /***********************************************************************************
	Function			: str_Reverse()
	Description			: This function reverse the string
	Input				: char*
	Output				: nothing

	@Author : Yuvraj Takey
*/
void str_Reverse(char *str)
{
	// if strings ends then return 
	if((*str) == '\0')
	{
		return;
	}
	
	// recursive call with increment by 1 character address
	str_Reverse(str+1);
	
	// printing a string character on screen
	printf("%c",*str);
	
	return;
}
 
 int main()
 {
 	char c_Text[MAXCHAR] = {'\0'};
 	
 	printf("Kindly enter any string\n");
 	scanf("%[^'\n']s",c_Text);
 
 	// calling to reverse fnction	
 	str_Reverse(c_Text);
 	
 	printf("\n");
 	
 	return 0;
 }
