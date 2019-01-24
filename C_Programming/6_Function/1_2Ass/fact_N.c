/*
 * Write a recursive function to find factorial of a number.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>

 /***********************************************************************************
	Function			: fact_Calc()
	Description			: This function calculates factorial of given number
	Input				: int
	Output				: int

	@Author : Yuvraj Takey
*/
int fact_Calc(int iVal)
{
	// recursive terminating condition
	if(iVal == 1)
	{
		return 1;
	}

	// return result
	return (iVal * fact_Calc(iVal-1));	
}
 
 int main()
 {
 	int iNum1 = 0, iNum2 = 0;

 	// accept value of n
 	printf("Kindly enter the value of n\n");
 	scanf("%d",&iNum1); 	

 	//printing result with recursive call
 	printf("The result is : %d\n", (fact_Calc(iNum1)));

 	return 0;
 }
