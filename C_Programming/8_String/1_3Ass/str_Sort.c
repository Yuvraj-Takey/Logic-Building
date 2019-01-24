/*
 *
 * a program to read n number of strings using two-dimensional character array, sort them and display the sorted list of strings on the screen.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdio_ext.h>
 #define MAXCHAR	80

/***********************************************************************************
	Function			: str_Sort()
	Description			: This function sort strings in ascending order
	Input				: char**, int
	Output				: nothing

	@Author : Yuvraj Takey
*/

void str_Sort(char **str, int i_Row)
{
	int i_index= 0, j_index = 0;
	char* temp = NULL;

	// iterate loop by row wise	
	for(i_index = 0; i_index < (i_Row-1); i_index++)
	{
		// maintain comparison index
		for(int i_Comp = (i_index+1); i_Comp < i_Row; i_Comp++)
		{
			// iterate loop by column wise
			for(j_index = 0; str[i_index][j_index] != '\0'; j_index++)
			{	
				// filter for comparaing each word
				if((str[i_index][j_index]) == (str[i_Comp][j_index]))
				{
					// if first word is same, check second one
					continue;
				}
				
				// if the left most word is greater then swap with right one
				if((str[i_index][j_index]) > (str[i_Comp][j_index]))
				{
					// swap logic
					temp = str[i_index];
					str[i_index] = str[i_Comp];
					str[i_Comp] = temp;
				}
				
				// break inner one loop
				break;
			}
		}
	}
	
	// decoration purpose
	printf("\n");
	
	return;
}
 
 int main()
 {
 	int i_NumStr = 0, index = 0;
 	char **c_str = NULL, c_flush = '\0';
 	
 	printf("Enter the number of string\n");
 	scanf("%d",&i_NumStr);
 	
 	// allocate the memory for 2 pointer dynamically
 	c_str = (char**)malloc(i_NumStr*sizeof(char*));
 	if(c_str == NULL)
 	{
 		printf("[SORRY] : Memory allocation failed\n");
 	}
	
	printf("Enter your string one by one\n");
	
 	// iterate the loop till the number provided by user
 	for(index = 0; index < i_NumStr; index++)
 	{
 		// allocate the memory for every character pointer dynamically
 		c_str[index] = (char*)malloc(MAXCHAR*sizeof(char));
 		if(c_str[index] == NULL)
 		{
 			printf("[SORRY] : Memory allocation failed\n");
 		}
 		
 		// clear screen buffer
 		__fpurge(stdin);	
 
 		
 		// store the string into allocated memory
 		scanf("%[^\n]s",c_str[index]);
 	}
 	
 	// calling to the function
 	str_Sort(c_str,i_NumStr);
 	
 	// printf all strings 
 	for(index = 0; index < i_NumStr; index++)
 	{
 		printf("%s\n",c_str[index]);
 	}	
 	
 	return 0;
 }
