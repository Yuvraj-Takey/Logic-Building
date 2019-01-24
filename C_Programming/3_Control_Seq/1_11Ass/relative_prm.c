/*
 *
 * program to generate two Relatively Prime numbers
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <stdlib.h>


/*******************************************************************************************************
	Function			: factors()
	Description			: This function calculate the factor of two given number,
					  if the commmon divisor is 1, it will print given number on screen
	Input				: int, int
	Output				: nothing

	@Author : Yuvraj Takey
*/

void factors(int i_value, int j_value)
{
	int index = 1, i_CommonFact = 0;
	
	// iterate loop till given number
	while((index <= i_value) && (index <= j_value))
	{
		// check for foctors, if both are divisible by same number then enter
		if((i_value % index == 0) && (j_value % index == 0))
		{
			// increase the counter as it got 1 divisor
			i_CommonFact++;
			
			// if divisor is greater than 1 then this number is not a relative prime number
			if(i_CommonFact > 1)
			{
				// break that loop
				break;
			}
		}
		
		// increment the index 
		index++;
	}
	
	// if after complition, i_ComonFact containt 1 (divisor), this will be our relative prime number
	if(i_CommonFact == 1)
	{
		printf("(%d,%d)\t",i_value,j_value);
	}

	return;
}


/********************************************************************************************************
	Function			: relative_Prm()
	Description			: This function iterates between range, provided by user
	Input				: int, int
	Output				: nothing

	@Author : Yuvraj Takey
*/
void relative_Prm(int i_range, int j_range)
{
	int i_index = 0, j_index = 0, i_length = (j_range-i_range)+1;
	int *ptr = NULL;
	
	// allocate the momory dynamically for storing the range element (range : provided buy user)	
	ptr = (int*)malloc(i_length*sizeof(int));
	
	// fill the array with the given range element
	// iterate the loop from starting range to ending range
	for(i_index = 0; i_index <= i_length; i_index++)
	{
		// assign the element to array
		ptr[i_index] = i_range++;		
	}
	
	printf("Relative Prime Numbers are:\n\n");
	
	// sepate out 2 element from array and pass it to function
	for(i_index = 0; i_index < (i_length-1); i_index++)
	{
		for(j_index = i_index+1; j_index < i_length; j_index++)
		{
			// calling function
			factors(ptr[i_index],ptr[j_index]);
		}
	}
		
	printf("\n");
	
	// free the allocated memory
	free(ptr);
	
	// initialize pointer to NULL
	ptr = NULL;
	
	return ;
}

int main()
{
	int i_range = 0, j_range = 0;
	
	printf("Enter the range for relative prime number\n");
	scanf("%d%d",&i_range,&j_range);

	// checking for filter (i.e: negative number and negative range)
	if((i_range > j_range) || ((i_range < 0) || (j_range < 0)))
	{
		printf("[SORRY] : Invalid range\n");
		return -1;
	}	

	// calling to the function with user range	
	relative_Prm(i_range,j_range);
	
	return 0;
}
