/*
 *		A C program contains the following declaration
 *		int x[8]= {10,20,30,40,50,60,70,80};
 *		 What is the meaning of x?
 *		 What is the meaning of (x+2)?
 *		 What is the value of *x?
 *		 What is the value of (*x+2)?
 *		 What is the value of *(x+2)?.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 
 int main()
 {
 	int x[8] = {10,20,30,40,50,60,70,80};
 	
 	// showing given data
 	printf("Here the given data is:\n");
 	printf("int x[8] = {10,20,30,40,50,60,70,80}\n\n");
 	
 	// printing the result
 	printf("The value of 'x' (i.e base address) is  : %p\n",x);
 	printf("The value of 'x+2' is \t\t\t: %p\n",(x+2));
 	printf("The value of '*x' is \t\t\t: %d\n",*x);
 	printf("The value of '*x+2' is \t\t\t: %d\n",(*x+2));
 	printf("The value of '*(x+2)' is \t\t: %d\n\n",*(x+2));
 	
 	return 0;
 }
