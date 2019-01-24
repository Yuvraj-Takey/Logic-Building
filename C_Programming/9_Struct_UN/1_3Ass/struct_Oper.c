/*
 * 	a) Define three bit fields, called a, b and c, whose widths are 6-bits, 4-bits and 6-bits, respectively
 *
 *	b) Declare a structure-type variable v having the composition defined in part (a) above. Assign initial values
 *	3, 5 and 7 respectively, to the three bit fields. Are the bit fields large enough to accommodate these
 *	values?
 *
 *	c) What are the largest values that can be assigned to each of the bit fields defined in part (a) above?
 *
 *	d) Define three bit fields, called a, b and c, whose widths are 8 bits, 6 bits and 5 bits, respectively. How will
 *	these fields be stored within the computer’s memory?
 *
 *	e) Define three bit fields, called a, b and c, whose widths are 8 bits, 6 bits and 5-bits respectively. Separate a
 *	and b with 2 vacant bits. 
 *
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>

// bit field
typedef struct st_struct
{
	unsigned int a : 6;
	unsigned int b : 4;
	unsigned int c : 6;
	
}ST_STRUCT;

// composition
typedef struct st_Composition
{
	ST_STRUCT st_Bit;
}ST_COMP;

// struct having vacant bit
typedef struct st_Vacant
{
	unsigned int a : 8;
	unsigned int   : 2;
	unsigned int b : 6;
	unsigned int c : 5;
}ST_VAC;

int main()
{
	// creating object of structures
	ST_STRUCT sobj;
	ST_COMP v;
	ST_VAC st_v;			// structure having vacant variable with 2 bit
	
	
	// initialiase the value
	v.st_Bit.a = 3;
	v.st_Bit.b = 5;
	v.st_Bit.c = 7;
	// printing result
	printf("value of a : %d\nvalue of b : %d\nvalue of c : %d\n",v.st_Bit.a,v.st_Bit.b,v.st_Bit.c);
	
	
	// the largest value is assigned
	v.st_Bit.a = 63;
	// printing result
	printf("Largest value that can store is : %d\n",v.st_Bit.a);
	
	
	return 0;
}
