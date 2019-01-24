/*
 * a program to count number of bits as “1” in an 8 bit number.
 *
 *	@Author - Yuvraj Takey
 *
*/

#include <stdio.h>
typedef unsigned short UINT;

/***********************************************************************************
	Function			: count_Once()
	Description			: This function calculate the number of once in given number
	Input				: unsigned short
	Output				: unsigned short

	@Author : Yuvraj Takey
*/

UINT count_Once(UINT s_Num)
{
	UINT s_Count = 0, s_Mask = 1, s_Result = 0;
	
	// iterate while till mask becomes 0 ( all bits becomes zero)
	while(s_Mask != 0)
	{
		// apply mask and perfom AND operation (only 1 & 1 becomes 1)
		s_Result = s_Num & s_Mask;
		
		// if the result and mask is same then increment counter
		if(s_Result == s_Mask)
		{
			s_Count++;
		}
		
		// shift the mask by 1 bit
		s_Mask = s_Mask << 1;
	}
	
	return s_Count;
}

int main()
{
	UINT s_Num = 0, s_Count = 0;
	
	printf("Enter any number (Max range : 255)\n");
	scanf("%hd",&s_Num);
	
	// check for value (which should not greater than 1byte)
	if(s_Num > 255)
	{
		printf("Please follow above condition\n-> please insert from below 255 value\n");
		return 1;
	}

	// calling to function	
	s_Count = count_Once(s_Num);
	
	// printing result
	printf("Number of once is : %d\n",s_Count);
		
	return 0;
}
