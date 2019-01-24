/*
 * program to search for an element in a given list of elements. Use break statement
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define ARRAY_LEN	10
 
 
 /***********************************************************************************
	Function			: search_Ele()
	Description			: This function search the given element into the given array
	Input				: int[], int, int
	Output				: nothing

	@Author : Yuvraj Takey
*/

 void search_Ele(int arr[], int i_Length, int i_element)
 {
	int index = 0;
	
	// traverse the array
	for(index = 0; index < i_Length; index++)
	{
		// filter for element checking
		if(arr[index] == i_element)
		{
			// if element found, break the loop
			break;
		}
	}
	
	// check filter	
	if(index != i_Length)
	{
		printf("[DONE_] : Element %d found on index : %d\n", i_element, index);
	}
	else
	{
		printf("[SORRY] : Element not present in the list\n");
	}
	 
 	return;
 }
 
 int main()
 {
 	int i_array[ARRAY_LEN] = {0}, i_element = 0;
 	
 	printf("Enter any %d array element\n",ARRAY_LEN);
 	
 	// filling the array on demand of user
 	for(int index = 0; index < ARRAY_LEN; index++)
 	{
 		scanf("%d",&(i_array[index]));
 	}
 	
 	printf("Enter the element that you want to search in the array\n");
 	scanf("%d",&i_element);
 	
 	// address of array, size of array, element that want to search
 	search_Ele(i_array, ARRAY_LEN ,i_element);
 	
 	return 0;
 }
