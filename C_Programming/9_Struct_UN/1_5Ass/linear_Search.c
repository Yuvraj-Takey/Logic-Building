/*
 * a program to search for a given element in a list of elements using Linear Search. Use flag to represent
 * the status of search. Define flag as an enumeration variable whose value is either true or false.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #define MAXCHAR	80

 /***********************************************************************************
	Function			: linearSearch()
	Description			: This function searches the given element in given list of element
	Input				: int*, int, int
	Output				: nothing

	@Author : Yuvraj Takey
*///		0,   1
enum status {FALSE, TRUE};

void linearSearch(int *ptr,int iLen,int iElem)
{
	enum status flag = FALSE;
	int index = 0;

	// iterate as linearly
	for (index = 0; index < iLen; ++index)
	{
		// search for element
		if(ptr[index] == iElem)
		{
			// on the flag
			flag  = TRUE;
			break;
		}
	}

	// check flag
	if(flag)
	{
		printf("[DONE_] : given element found in %d location\n", index);
	}
	else
	{
		printf("[SORRY] : given element is not in the list\n");
	}
}
 
 int main()
 {
 	int iSize = 0, iElem = 0;
 	int *ptr = NULL;

 	// acccept size of list
 	printf("Kindly enter the size of element list\n");
 	scanf("%d",&iSize);

 	// dynamic memory allocation
 	ptr = (int*)malloc(iSize*sizeof(int));

 	printf("Enter the %d element in list\n",iSize);

 	// iterate for loop that accept the element in list
 	for (int i = 0; i < iSize; ++i)
 	 {
 	 	scanf("%d",&(ptr[i]));
 	 } 

 	// accept search element
 	printf("Enter the element that you want to search\n");
 	scanf("%d",&iElem);

 	linearSearch(ptr,iSize,iElem);
 
 	// freee the dynamic memory
 	free(ptr);
 	ptr = NULL;
 	return 0;
 }
