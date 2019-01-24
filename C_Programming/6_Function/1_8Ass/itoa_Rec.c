/*
 * a C program with a recursive function itoa, which converts integer into a string.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
#include <string.h>
 #define MAXCHAR 	80
 #define ASCII_NUM	48

/***********************************************************************************
	Function			: str_rev()
	Description			: This function reverse the given string
	Input				: char*, int
	Output				: int

	@Author : Yuvraj Takey
*/
 int str_rev(char *str, int i_Len)
 {
 	int i_index = 0;
 	char c_temp = ' ';
 	
 	// decrement counter by one 
 	i_Len--;
 	
 	// iterate till condition fails 	
 	for(i_index = 0; i_index < (i_Len-i_index); i_index++)
 	{
 		// swaping inplace logic
 		c_temp = str[i_index];
 		str[i_index] = str[i_Len-i_index];
 		str[i_Len-i_index] = c_temp;
 	}
 		
 	return 0;
 }


 /***********************************************************************************
	Function			: itoa_Rec()
	Description			: This function converts given interger into string format
	Input				: int, char*
	Output				: nothing

	@Author : Yuvraj Takey
*/
void itoa_Rec(int iVal, char *ptr)
{
	// recursive terminating condition
	if(iVal == 0)
	{
		*ptr = '\0';
		return ;
	}

	int iDigit = 0;

	iDigit = iVal % 10;
	*ptr = iDigit + ASCII_NUM;
	iVal = iVal / 10;

	// recursive call
	itoa_Rec(iVal,ptr+1);

	return;
}
 
 int main()
 {
 	int iNum1 = 0;
 	char c_arr[MAXCHAR] = {'\0'};

 	// accept value of n
 	printf("Kindly enter the integral value\n");
 	scanf("%d",&iNum1); 	

 	// function calling
 	itoa_Rec(iNum1,c_arr);

 	// reverse the string
	str_rev(c_arr,strlen(c_arr));

 	//printing result
 	printf("The result is : %s\n", c_arr);

 	return 0;
 }
