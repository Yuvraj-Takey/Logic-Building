/*
 * Read a positive integer value, and compute the following sequence: If the number is even, halve it; if it's odd, multiply by 3 and add 1.
 * Repeat this process until the value is 1, printing out each value. Finally print out how many of these operations you performed
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int main()
 {
 	int i_Num = 0, iCount = 0;
 	
 	// accept input
 	printf("Kindly enter any positive integral value\n");
 	scanf("%d",&i_Num);
 	
 	// chaeck filters
 	if(i_Num < 0)
 	{
 		printf("You crazy buddy !!\n I told POSITIVE integer\n\n");
 		return -1;
 	}
 	else if(i_Num == 1)
 	{
 		printf("[Error] : the value is not accetable\n");
 		exit(0);
 	}
 	
 	// iterate till number becomes zero
 	while(i_Num != 1)
 	{
 		// check for even number
 		if((i_Num % 2) == 0)
 		{
 			i_Num = i_Num / 2;
 			printf("Next value %d\n",i_Num);
 		}
 		else
 		{
 			i_Num = ((i_Num * 3) + 1);
 			printf("Next value %d\n",i_Num);
 		}
 	
 		// increment step count		
 		iCount++;
 	}

	// printing the final result 	
 	printf("The number of operation performed is : %d steps\n",iCount);
 	
 	return 0;
 }
