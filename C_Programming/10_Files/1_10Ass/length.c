/*
 * a program to read English text to end-of-data (type control-D to indicate end of data at a terminal, see below for detecting it),
 * and print a count of word lengths, i.e. the total number of words of length 1 which occurred, the number of length 2, and so on.
 *
 *
 *	@Author - Yuvraj Takey
 */
 #include <stdio.h>
 #define	MAXLETTER	26
 #define	TRUE		1
 #define	FALSE		0
 
 int main()
 {
 	char ch = ' ', flag = TRUE;
 	int arr[MAXLETTER] = {0}, i_size = 0, index = 0;
 	
 	printf("Kindly provide some English text (Terminate using : control+D)\n");
 	
 	// iterate till end of file
 	while((ch = getchar()) != EOF)
 	{
 		// only accept letters
 		if(((ch >= 'A') && (ch <='Z')) || ((ch >= 'a') && (ch <='z')))
 		{
 			// count letters in one word
 			i_size++;
 		}
 		else
 		{
 			// if limit reaches greater than 25
 			if(i_size > (MAXLETTER-1))
 			{
 				flag = FALSE;
 				printf("[SORRY] : Word length should not greater than 25 letters\n");
 				break;
 			}
 			else
 			{
 				// check of 0 size
 				if(i_size != 0)
 				{
 					// increment array index which is matching with the length of word
 					arr[i_size]++;
 					i_size = 0;
 				}
 			}
 		}
 	} // end of while
 	
 	// check for invalid characters
 	if(flag == TRUE)
 	{
 		printf("Result :\n");
 		
 		// iterate whole array and show their occurrance
 		for(index = 1; index < MAXLETTER; index++)
 		{
 			// printing all calculations
 			printf("length \t%d \t: %d occurrences\n",index,arr[index]);
 		}
 	}
 	
 	return 0;
 }
 
