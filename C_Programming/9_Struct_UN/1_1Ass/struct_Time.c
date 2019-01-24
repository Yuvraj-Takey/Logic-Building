/*
 * Write a program to represent time of the day in hrs, mins and secs. Use structures.
 *
 *	@Author - Yuvraj Takey
 */
 
 #include <stdio.h>
 #include <time.h>
 
 // program local structure
 typedef struct stTime
 {
 	int hr;		// hour
 	int min;	// minute
 	int sec;	// second
 }S_TIME;
 
 int main()
 {
 	S_TIME oTime;
 	time_t t = time(NULL);
 	struct tm *st_tm = localtime(&t);

	// getting system time in our local structure
	oTime.hr = st_tm->tm_hour;
	oTime.min = st_tm->tm_min;
	oTime.sec = st_tm->tm_sec;
	
	// printing result
	printf("Hour : %d   Min : %d   Sec : %d\n\n",oTime.hr,oTime.min,oTime.sec);
 
 	return 0;
 }
