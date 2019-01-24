/*
 * calculate simple interest using the formula I=PTR/100. Display Interest with two digit precision after decimal point
 *
 * @Author - Yuvraj Takey
*/

#include <stdio.h>

/***********************************************************************************
	Function			: calInterest()
	Description			: This function calculate the interest
	Input				: int, int, float
	Output				: float

	@Author : Yuvraj Takey
*/

float calInterest(int amount, int time, float rate)
{
	return ((amount*time*rate)/100);
}


int main()
{
	int i_amount = 0, i_time = 0;
	float f_rate = 0.0f, f_result = 0.0f;
	
	printf("Enter the price amount\n");
	scanf("%d",&i_amount);
	
	printf("Enter the time period (in terms of year)\n");
	scanf("%d",&i_time);
	
	printf("Enter the rate for interest\n");
	scanf("%f",&f_rate);

	f_result = calInterest(i_amount, i_time, f_rate);
	
	printf("The interest is : %.2f\n", f_result);

	return 0;
}
