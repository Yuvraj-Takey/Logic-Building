/* write a menu based C program to perform operations (+, - and *) on matrices.
 *
 * @Author - Yuvraj Takey
 *
 */

#include <stdio.h>
#define RUN 	1
#define ROW	2
#define COL	2
#define TRUE	1
#define FALSE	0

/***********************************************************************************
	Function			: acceptMatrix
	Description			: This function accept input from user and fill the matrix 
	Input				: int*, int*
	Output				: Nothing

	@Author : Yuvraj Takey
*/
void acceptMatrix(int* ptr1, int* ptr2)
{
	short i_index = 0;
	
	printf("Enter the element for first matrix\n");
	
	for(i_index = 0; i_index < (ROW*COL); i_index++)
	{
		scanf("%d",&(*ptr1));
		ptr1++;
	}
	
	printf("Enter the element for second matrix\n");
	
	for(i_index = 0; i_index < (ROW*COL); i_index++)
	{
		scanf("%d",&(*ptr2));
		ptr2++;
	}
	
	return;
}

/***********************************************************************************
	Function			: matrix_Add
	Description			: This function make addition of two matrices
	Input				: int*, int*, int*
	Output				: Nothing

	@Author : Yuvraj Takey
*/
void matrix_Add(int* i_ptr1, int* i_ptr2, int* i_result)
{
	short s_index = 0;
	
	for(s_index = 0; s_index < (ROW*COL); s_index++)
	{
		// Like :   arr[0] = brr[0] + crr[0];
		i_result[s_index] = i_ptr1[s_index] + i_ptr2[s_index];
	}
	
	return;
}

/***********************************************************************************
	Function			: matrix_Sub
	Description			: This function make substraction of two matrices
	Input				: int*, int*, int*
	Output				: Nothing

	@Author : Yuvraj Takey
*/
void matrix_Sub(int* i_ptr1, int* i_ptr2, int* i_result)
{
	short s_index = 0;
	
	for(s_index = 0; s_index < (ROW*COL); s_index++)
	{
		// Like :   arr[0] = brr[0] - crr[0];
		i_result[s_index] = i_ptr1[s_index] - i_ptr2[s_index];
	}
	
	return;
}


/***********************************************************************************
	Function			: matrix_Mult
	Description			: This function make multiplication of two matrices
	Input				: int*, int*, int*
	Output				: Nothing

	@Author : Yuvraj Takey
*/

void matrix_Mult(int i_ptr1[ROW][COL], int i_ptr2[ROW][COL], int i_result[ROW][COL])
{	
	// If columns of first matrix is equal to the rows of second matrix then only Multiplication will perform
	
	short k_index = 0, j_index = 0, i_index = 0;
	

	for(i_index = 0; i_index < (ROW); i_index++)
	{
		for(j_index = 0; j_index < (ROW); j_index++)
		{
			for(k_index = 0; k_index < (ROW); k_index++)
			{
		
				i_result[i_index][j_index] = i_result[i_index][j_index] + (i_ptr1[i_index][k_index] * i_ptr2[k_index][j_index]);
			}
		}
	}
	
	return;
}



/***********************************************************************************/	

int main()
{
	short s_Input = 0, s_flag_Show = FALSE;
	int i_index = 0, j_index = 0;
	int i_arr1[ROW][COL] = {0}, i_arr2[ROW][COL] = {0}, i_result[ROW][COL] = {0};
	
	// Accept the value in the matrix from user
	acceptMatrix(i_arr1,i_arr2);
	
	// unstopable loop
	while(RUN)
	{
		// menu
		printf("\nSelect the operation\n");
		printf("1.	Addition of matrix\n");
		printf("2.	Substraction of matrix\n");
		printf("3.	Multiplication of matrix\n");
		printf("4.	Exit\n");
		printf("Your choice	_ ");

		scanf("%hd",&s_Input);
	
		if(s_Input < 0)
		{
			printf("sorry : Invalid Input\n");
			continue;
		}

		if(s_Input == 4) { break;}

		switch(s_Input)
		{
			
			case 1:
				matrix_Add(i_arr1,i_arr2,i_result);
				
				// condition for showing the result_matrix
				s_flag_Show = TRUE;
				break;
			case 2:
				matrix_Sub(i_arr1,i_arr2,i_result);
				
				// condition for showing the result_matrix
				s_flag_Show = TRUE;
				break;
			case 3:
				matrix_Mult(i_arr1,i_arr2,i_result);
				
				// condition for showing the result_matrix
				s_flag_Show = TRUE;
				break;
			default:
				printf("sorry : Input number not in the list");
				break;
		}
		
		
		// If it is TRUE, show the result_matrix
		if(s_flag_Show == TRUE)
		{
			for(i_index = 0; i_index < ROW; i_index++)
			{
				for(j_index = 0; j_index < COL; j_index++)
				{
					printf("%d\t",i_result[i_index][j_index]);
				}
				
				printf("\n");
			}
			
			// reset the result array
			memset(i_result,0,(ROW*COL*sizeof(int)));
			
			// reset the flag variable
			s_flag_Show = FALSE;
		}				
	}

	return 0;
}
