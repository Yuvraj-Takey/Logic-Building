/*
 * Given as input an integer number of seconds, print as output the equivalent time in hours, minutes and seconds.
 * Recommended output format is something like 7322 seconds is equivalent to 2 hours 2 minutes 2 seconds.
 *
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #define T_UNIT		60
 
 typedef struct sTime
 {
 	short hr;
 	short min;
 	short sec;
 }TIME;

 /***********************************************************************************
	Function			: timeFormat()
	Description			: This function converts seconds into appropriate time format
	Input				: int
	Output				: struct sTime

	@Author : Yuvraj Takey
*/

 TIME timeFormat(int i_Sec)
 {
 	// take time structure
 	TIME st;
 	
 	// initialise time structure by doing modulo operation
 	st.sec = i_Sec % T_UNIT;
 	i_Sec = i_Sec/T_UNIT;
 	
 	st.min = i_Sec % T_UNIT;
 	i_Sec = i_Sec/T_UNIT;
 	
 	st.hr = i_Sec % T_UNIT;	
 	i_Sec = i_Sec/T_UNIT;
 	
 	// return time structure to calli
 	return st;
 }
 
 int main()
 {
 	TIME st;
 	int i_Sec = 0;
 	
 	// accept input from user in form of seconds
 	printf("Enter number in seconds format\n");
	scanf("%d",&i_Sec);
	
	// calling to function
	st = timeFormat(i_Sec);
	
	// printing output on screen
	printf("Output:\n%u Hour  %u Minute  %u Second\n",st.hr, st.min, st.sec);

 	return 0;
 }
