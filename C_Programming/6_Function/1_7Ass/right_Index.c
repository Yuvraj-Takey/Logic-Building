/*
 * a C program with a function indexr(s,t), which returns the index of right most occurrence of t in s
 * otherwise -1.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdio_ext.h>
 #define MAXCHAR	80

 /***********************************************************************************
	Function			: indexr()
	Description			: This function returns the right most occurance of character in given string
	Input				: char *, char
	Output				: int

	@Author : Yuvraj Takey
*/
int indexr(char *str, char find)
{
	int index = 0, prevs = 0;
	
	// iterate while till end of string
	while(*str != '\0')
	{
		// check for character match
		if(*str == find)
		{
			// preserv the latest index
			prevs = index;
		}
		
		// increment count
		index++;
		
		// increment the address of character
		str++;
	}
	
	// return the recently got index
 	return prevs;
}
 
 int main()
 {
 	char c_arr[MAXCHAR] = {'\0'}, find = ' ';
 	
 	// accept input
 	printf("Kindly enter the string\n");
 	scanf("%[^'\n']s",c_arr);

	printf("Kindly enter the character that you want right most index\n"); 	
 	__fpurge(stdin);
 	scanf("%c",&find);
 	
 	//printing the result
 	printf("Here the index of right most occ. is : %d\n",indexr(c_arr,find));
 	
 	return 0;
 }
