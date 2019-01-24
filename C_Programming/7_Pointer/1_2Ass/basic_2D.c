/*
 *		A C program contains the following declaration
 *		float table[2][3] = { { 1.1,1.2,1.3},{2.1,2.2,2.3}};
 *		a) What is the meaning of a table?
 *		b) What is the meaning of (table+1)?
 *		c) What is the meaning of *(table+1)?
 *		d) What is the meaning of (*(table+1)+1)?
 *		e) What is the meaning of (*(table)+1)?
 *		f) What is the value of *(*(table+1) +1)?
 *		g) What is the value of *(*(table)+1)?
 *		h) What is the value of *(*(table+1)?
 *		i) What is the value of *(*(table) + 1)+1?
 *
 *	@Author - Yuvraj Takey
 *
*/

#include <stdio.h>

int main()
{
	float table[2][3] = { {1.1,1.2,1.3},{2.1,2.2,2.3} };
	
	// printing given term
	printf("Here the given input is :\n");
	printf("float table[2][3] = { {1.1,1.2,1.3},{2.1,2.2,2.3} }\n\n");
	
	// printing result
	printf("The meaning of table is \t\t: %p\n",table);
	printf("The meaning of (table+1) is \t\t: %p\n",(table+1));
	printf("The meaning of *(table+1) is \t\t: %p\n",*(table+1));
	printf("The meaning of (*(table+1)+1) is \t: %p\n",(*(table+1)+1));
	printf("The meaning of (*(table)+1) is \t\t: %p\n",(*(table)+1));
	printf("The meaning of *(*(table+1) +1) is \t: %.1f\n",*(*(table+1) +1));
	printf("The meaning of *(*(table)+1) is \t: %.1f\n",*(*(table)+1));
	printf("The meaning of *(*(table+1) is \t\t: %.1f\n",*(*(table+1)));
	printf("The meaning of *(*(table) + 1)+1 is \t: %.1f\n\n",*(*(table) + 1)+1);
	
	return 0;
}
