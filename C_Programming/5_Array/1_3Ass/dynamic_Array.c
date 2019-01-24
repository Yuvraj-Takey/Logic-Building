/*
 *
 * a program that reads a number that says how many integer numbers are to be stored in an array,
 * creates an array to fit the exact size of the data and then reads in that many numbers into the array.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main()
 {
 	char flag = 0;
 	int *dynamic = NULL, i_count = 0,index = 0;
 	
 	printf("Enter, how many number of element that you want to store into array\n");
 	scanf("%d",&i_count);
 
 	// allocate memory dynamically	
 	dynamic = (int*)malloc(i_count*sizeof(int));
 	
 	printf("Enter the %d element to store it into array\n",i_count);
 	
 	// fill the element of array
 	for(int index = 0; index < i_count; index++)
 	{
 		scanf("%d",&(dynamic[index]));
 	}
 	
 	printf("Do you want to print the array?(y/n)_");
 	scanf(" %c",&flag);
 	
 	// filter checking
 	if((flag == 'y') || (flag == 'Y'))
 	{
 		// print the array on screen
 		for(index = 0; index < i_count; index++)
 		{
 			printf("%d\n",dynamic[index]);
 		}
 	}
 	
 	return 0;
 }
