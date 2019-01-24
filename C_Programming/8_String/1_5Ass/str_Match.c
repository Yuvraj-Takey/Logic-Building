/*
 * program with a function any (s1, s2). This function returns the first location (index of location) in the string s1
 * which matches with any string in s2 otherwise.
 *
 *	@Author - Yuvraj Takey
 *
 */
 
 #include <stdio.h>
 #include <stdio_ext.h>
 #define MAXCHAR	80

/***********************************************************************************
	Function			: str_Any()
	Description			: This function searches character occurance of 2nd string in 1st string
	Input				: char[], char[]
	Output				: nothing

	@Author : Yuvraj Takey
*/ 
 // s1[] = 100	=> i.e addressof("Helo")
 void str_Any(char s1[MAXCHAR], char s2[MAXCHAR])
 {
 	int i_index = 0,j_index = 0;
 	
 	// iterate S2 till end
 	for(i_index = 0; s2[i_index] != '\0'; i_index++)
 	{
 		// iterate s1 string till end
 		for(j_index = 0; s1[j_index] != '\0'; j_index++)
 		{
 			// see 1st occurance of character in 1st string
 			if(s2[i_index] == s1[j_index])
 			{
 				printf("first occurance of '%c' on index : %d\n",s2[i_index],j_index);
 				break;
 			}
 		}
 	}
 
 	return;
 }
 
 int main()
 {
 	char c_arr1[MAXCHAR] = {'\0'}, c_arr2[MAXCHAR] = {'\0'};
 	
 	printf("Kindly enter 1st string\n");
 	scanf("%[^'\n']s",c_arr1);
 	
 	// flush buffer
 	__fpurge(stdin);
 	
 	printf("Kindly enter 2nd string\n");
 	scanf("%[^'\n']s",c_arr2);
 
 	printf("Result:-\n");	
 	// calling to the function
 	str_Any(c_arr1,c_arr2);
 	
 	return 0;
 }
