/*
 * a C program to calculate factorial of a number. Factorial function has to be written as a multiline macro.
 *
 *	@Author - Yuvraj Takey
 *
 */
 
 #include <stdio.h>
 #define RUNNING	1
#define FACT(i_Num) 	({					\
	for(index = 1; index <= i_Num; index++)			\
 	{							\
 		iFact = iFact * index;				\
 	} })							
 
 int main()
 {
 	int i_Num = 0, iFact = 1, index = 0;
 	
 	// accept input from user
 	printf("Kindly enter a number for factorial\n");
 	scanf("%d",&i_Num);

	// MACRO Call 	
 	FACT(i_Num);
 	
 	// print output
 	printf("Factorial of a given number is %d\n",iFact);  		
 	
 	return 0;
 }
