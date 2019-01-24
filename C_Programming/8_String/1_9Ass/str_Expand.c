/*
 * a function expand (s, t) which converts characters like newline and tab into visible escape sequences like \n and \t
 * as it copies the string s to t. Use switch statement and also display both s and t at the end.
 *
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define MAXCHAR	80
 
 
 /***********************************************************************************
	Function			: expand()
	Description			: This function converts non-printable character as printable (as \n and \t)
	Input				: char*, char*
	Output				: void

	@Author : Yuvraj Takey
*/
 void expand(char *s, char *t)
 {
 	// iterate while till string of the string
 	while(*s != '\0')
 	{
 		// conditional statement
 		switch(*s)
 		{
 			case '\t':
 				// copy non-visible character to t.
 				*t = 92;
 				t++;
 				*t = 't';
 			break;
 			
 			case '\n':
 				// copy non-visible character to t.
 				*t = 92;	// ascii of '\'
 				t++;
 				*t = 'n';
 			break;
 			
 			default:
 				// copy visible character to t.
 				*t = *s;
 			break;
 		}
 		
 		
 		// increment the character addresses
 		s++;
 		t++;
 	}
 	
 	return;
 }
 
 int main()
 {
 	char c_Arr1[MAXCHAR] = {'\0'}, c_Arr2[MAXCHAR] = {'\0'};
 	
 	printf("Enter string (include : newline and tabs, use tilda(~) symbol for terminate)\n");
 	scanf("%[^'~']s",c_Arr1);
 	
 	// passing addresses to the function
 	expand(c_Arr1,c_Arr2);
 	
 	// printing result	
 	printf("Actual string is : %s\nYour Result: %s\n",c_Arr1,c_Arr2);
 	
 	return 0;
 }
