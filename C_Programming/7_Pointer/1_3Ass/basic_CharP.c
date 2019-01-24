/*
 *		A C program contains the following declaration
 *		char *color[6] = {“red”, “green”, “blue”, “white”, “black”, “yellow”};
 *		a. What is the meaning of color?
 *		b. What is the meaning of (color+2);
 *		c. What is the value of *color?
 *		d. What is the value of *(color+2)?
 *		e. How do color[5] and *(color + 5) differ?.
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>

int main()
{
	// array of charcater pointer
	char *color[6] = {"red","green","blue","white","black","yellow"};
	
	// printing given input
	printf("Here the given input is\n");
	printf("char *color[6] = {''red'',''green'',''blue'',''white'',''black'',''yello''}\n\n");
	
	// printing result
	printf("Color is the array 1-D array which contains each element as character pointer\n");
	printf("The meaning of (color+2) is \t\t : %p\n",(color+2));
	printf("The value of *color is \t\t\t : %s\n",*color);
	printf("The value of *(color+2) is \t\t : %s\n",*(color+2));
	printf("color[5] is : %s  and  *(color+5) is : %s\n\n",color[5],*(color+5));
	
	return 0;
}
