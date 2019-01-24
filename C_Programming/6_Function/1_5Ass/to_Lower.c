/*
 * a C program with a function tolower, which converts upper case letters to lower case. Use conditional expression.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
#define MAXCHAR 80

 /***********************************************************************************
	Function			: tolowerX()
	Description			: This function converts upper case to lower case letter
	Input				: char*
	Output				: nothing

	@Author : Yuvraj Takey
*/
void tolowerX(char *str)
{
		// iterate while till end of string
		while(*str != '\0')
		{
			// chaeck for  upper case letter
			if((*str >= 'A') && (*str <= 'Z'))
			{
				// replace this letter with lower leter
				*str = *str + 32;
			}

			// increase character address by one
			str++;
		}
}
 
 int main()
 {
 	char c_arr[MAXCHAR] = {'\0'};

 	// accept value of n
 	printf("Kindly enter any string (include: upper and lower case)\n");
 	scanf("%[^'\n']s",c_arr); 	

 	// calling to the function (call by address)
 	tolowerX(c_arr);

 	//printing result
 	printf("The result is : %s\n",c_arr);

 	return 0;
 }
