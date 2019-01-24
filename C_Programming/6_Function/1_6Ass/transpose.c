/*
 * a function to get the transpose of a matrix.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdlib.h>

 /***********************************************************************************
	Function			: transp_Matrix()
	Description			: This function gives transpose of matrix
	Input				: int**,int,int
	Output				: nothing

	@Author : Yuvraj Takey
*/
void transp_Matrix(int **ptr,int row, int col)
{
	int index = 0, j_index = 0, **Tptr = NULL;
	
	// printing actual mattrix
	printf("Here the matrix is :\n");
	for(index = 0; index < row; index++)
 	{
 		for(j_index = 0; j_index < col; j_index++)
		{ 
 			printf("%d\t",ptr[index][j_index]);
 		}
 		
 		printf("\n");
 	}
 	
 	
 	// allocate memory dynamically for rows
 	Tptr = (int**)malloc(col * sizeof(int*));
 	
 	// allocate memory for columns
 	for(index = 0; index < col; index++)
 	{
 		Tptr[index] = (int*)malloc(row * sizeof(int));
 	}
 	
 	// fill that memory with user input
 	for(index = 0; index < row; index++)
 	{
 		for(int j_index = 0; j_index < col; j_index++)
		{ 
 			Tptr[j_index][index] = ptr[index][j_index];
 		}
 	}
	
	
	printf("Transpose of matrix is :\n");
	// printing the transpose result	
	for(index = 0; index < col; index++)
 	{
 		for(j_index = 0; j_index < row; j_index++)
		{ 
 			printf("%d\t",Tptr[index][j_index]);
 		}
 		
 		printf("\n");
 	}
 	
 	
 	// free allocated memory
 	for(index = 0; index < col; index++)
 	{
 		free(Tptr[index]);
 	}
 	
 	// free ptr (rows) and initiate pointer to null
 	free(Tptr);
 	Tptr = NULL;
 	
 	
 	return ;
}
 
 int main()
 {
 	int m_Val = 0, n_Val = 0, index = 0, j_index = 0;
 	int **ptr = NULL;
 	
 	printf("Kindly enter the size of matix in terms of 'm' and 'n'\n");
 	scanf("%d%d",&m_Val,&n_Val);
 	
 	// allocate memory dynamically for rows
 	ptr = (int**)malloc(m_Val * sizeof(int*));
 	
 	// allocate memory for columns
 	for(index = 0; index < m_Val; index++)
 	{
 		ptr[index] = (int*)malloc(n_Val * sizeof(int));
 	}
 	
 	printf("Kindly fill the matrix with integral values\n");
 	
 	// fill that memory with user input
 	for(index = 0; index < m_Val; index++)
 	{
 		for(int j_index = 0; j_index < n_Val; j_index++)
		{ 
 			scanf("%d",&(ptr[index][j_index]));
 		}
 	}
 	
 	// calling to the function
 	transp_Matrix(ptr,m_Val,n_Val);
 	
 	// free allocated memory for columns
 	for(index = 0; index < m_Val; index++)
 	{
 		free(ptr[index]);
 	}
 	
 	// free ptr (rows) and initiate pointer to null
 	free(ptr);
 	ptr = NULL;
 	
 	return 0;
 }
