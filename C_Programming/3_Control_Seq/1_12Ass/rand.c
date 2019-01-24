/*
 *
 * a program to generate Random number
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <time.h>

int generate_Rand(int i_Num)
{
	int i_RndNum = 0;
	time_t t = time(NULL);		// get time field in time_t structure
	struct tm *st_time;		// time structure pointer
	
	// get current local time
	st_time = localtime(&t);
	
	// calculate the operation to get the random number
	i_RndNum = ((i_Num ^ ((st_time->tm_sec) * (st_time->tm_min))) ^ (st_time->tm_sec));
		
	return i_RndNum;
}

int main()
{
	int i_Num = 0, i_RandNum = 0;
	
	printf("Enter any number\n");
	scanf("%d",&i_Num);
	
	// calling to the function that will generate random number
	i_RandNum = generate_Rand(i_Num);
	
	printf("Your Number is : %d\n",i_RandNum);
	
	return 0;
}
