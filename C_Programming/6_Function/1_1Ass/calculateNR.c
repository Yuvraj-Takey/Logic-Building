/*
 * Write a program to calculate n!/(n-r)! using functions.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>

 /***********************************************************************************
	Function			: calculate()
	Description			: This function calculate n!/(n-r)!
	Input				: int
	Output				: int

	@Author : Yuvraj Takey
*/
int calculate(int iVal)
{
	int iCal = 1;

	// iterate till index becomes iVal
	for (int index = 1; index <= iVal; ++index)
	{
		// calculate multiplication
		iCal = iCal * index;
	}

	// return result
	return iCal;	
}
 
 int main()
 {
 	int iNum1 = 0, iNum2 = 0;

 	// accept value of n
 	printf("Kindly enter the value of n\n");
 	scanf("%d",&iNum1);

 	// accept value of r
 	printf("Kindly enter the value of r\n");
 	scanf("%d",&iNum2);
 	

 	//printing result
 	printf("The result is : %d\n", (calculate(iNum1) / calculate(iNum1-iNum2)));

 	return 0;
 }
