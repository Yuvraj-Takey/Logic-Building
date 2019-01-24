/*
 * Implement string library functions. strrev, strcpy, strcat, strcmp with same return values and
 * all error handling features using pointers.
 *
 *	@Author - Yuvraj Takey
 *
 */
 
 #include <stdio.h>
 #include <stdio_ext.h>
 #include <string.h>
 #define STOP		0
 #define MAXCHAR	80
 #define RUNNING	1
 
 /***********************************************************************************
	Function			: str_rev()
	Description			: This function reverse the given string
	Input				: char*, int
	Output				: int

	@Author : Yuvraj Takey
*/
 int str_rev(char str[MAXCHAR], int i_Len)
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
	Function			: str_cpy()
	Description			: This function copies the source string into destination
	Input				: char*, char*
	Output				: int

	@Author : Yuvraj Takey
*/
 int str_cpy(char *s1, char *s2)
 {
 	char ch = ' ';
 	short s_Count = 0;
 	
 	// iterate while till end of the string
 	while((ch = (*s2 = *s1)) != '\0')
 	{
 		// increment the address of character
 		s1++;
 		s2++;
 		
 		// number of characters are copied
 		s_Count++;
 	}
 	
 	// return character count
 	return s_Count;
 }
 
 /***********************************************************************************
	Function			: str_cat()
	Description			: This function concatinate two strings into destination string
	Input				: char*, char*, int
	Output				: int

	@Author : Yuvraj Takey
*/
 int str_cat(char *sr, char *des, int i_Len_des)
 {
 	short s_Count = 0;
 	
 	// iterate till end of second string
 	while(*des != '\0')
 	{
 		// increment address character by character
 		des++;
 	}
 	
 	// copy data of string1(sr) into string2(des)
 	while((*des = *sr) != '\0')
 	{
 		// increment the address both string, character by character
 		sr++;
 		des++;
 		
 		// maintain counter
 		s_Count++;
 		
 		if(s_Count == i_Len_des)
 		{
 			printf("[SORRY] : Size limit exceeded\n");
 			break;
 		}
 	}
 		
 	
 	return s_Count;
 }
 
 /***********************************************************************************
	Function			: calInterest()
	Description			: This function compares two string and return the differnce of both
	Input				: char*, char*
	Output				: int

	@Author : Yuvraj Takey
*/
 int str_cmp(char *sr, char *des)
 {
 	// iterate while till both character are matching
 	while(*sr == *des)
 	{
 		// increment the address of character
 		sr++;
 		des++;
 		
 		// check if string becomes end
 		if((*sr == '\0') || (*des == '\0'))
 		{
 			break;
 		}
 	}
 
 	// return the current character differences
 	return ((*sr)-(*des));
 }
 
 /********************************************************************************************/
 
 int main()
 {
 	char c_arr1[MAXCHAR] = {'\0'}, c_arr2[MAXCHAR] = {'\0'}, input;
 	
 	while(RUNNING)
 	{
 		// flush the buffer
	 	__fpurge(stdin);
	 	
	 	// flush memory
 		memset(c_arr1,0,MAXCHAR);
 		memset(c_arr2,0,MAXCHAR);
 		
	 	printf("Kindly choose your operation\n");
	 	printf("1.	strrev\n");
	 	printf("2.	strcpy\n");
	 	printf("3.	strcat\n");
	 	printf("4.	strcmp\n");
	 	printf("5.	exit\n");
	 	scanf("%c",&input);
	 	
	 	// flush the buffer
	 	__fpurge(stdin);
	 		
	 	switch(input)
	 	{	 		
	 		case '1':
	 			printf("'It will return the reversed string'\n");
	 			printf("Kindly enter a string for reverse operation\n");
	 			scanf("%[^'\n']s",c_arr1);
	 			str_rev(c_arr1,strlen(c_arr1));
	 			printf("The string is reversed:\n%s\n\n",c_arr1);
				break;
	 		
	 		case '2':
	 			printf("'It will return number of character is copied'\n");
	 			printf("Kindly enter source string for copy operation\n");
	 			scanf("%[^'\n']s",c_arr1);
				printf("Given string is successfully copied : %d element\nResult : %s\n\n",str_cpy(c_arr1,c_arr2),c_arr2);
	 			break;
	 		
	 		case '3':
	 			printf("'It will return number of character is concatinate'\n");
	 			printf("Kindly enter first string\n");
	 			scanf("%[^'\n']s",c_arr1);
	 			__fpurge(stdin);
	 			printf("Kindly enter second string\n");
	 			scanf("%[^'\n']s",c_arr2);
				printf("The number of character is concatinate : %d\nResult : %s\n\n",str_cat(c_arr1,c_arr2,sizeof(c_arr2)),c_arr2);
	 			break;
	 		
	 		case '4':
	 			printf("'It will return the differences of both'\n");
	 			printf("Kindly enter first string\n");
	 			scanf("%[^'\n']s",c_arr1);
	 			__fpurge(stdin);
	 			printf("Kindly enter second string\n");
	 			scanf("%[^'\n']s",c_arr2);
				printf("The compared difference is : %d\n\n",str_cmp(c_arr1,c_arr2));
	 			break;
	 		
	 		case '5':
	 			input = STOP;
	 			break;
	 		
	 		default:
	 			printf("[SORRY] : invalid input\n");
	 			break;
	 	}
	 	
	 	if(input == STOP)
	 	{
	 		// break RUNNING while loop
	 		break;
	 	}
	 }
	 
 	return 0;
 }
