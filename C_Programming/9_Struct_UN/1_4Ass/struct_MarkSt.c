/*
 * a program to generate marks sheet of C-DAC, Hyderabad Students (DSSD, DESD and DAC courses). 
 * Modules are different for each course. Implement this using structures, unions, arrays, loops and variables.
 *
 *
 *	@Author - Yuvraj Takey
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define SUBJECT_LEN	4
#define SUBJECT_DAC	7
#define SUBJECT_DSSD	5
#define SUBJECT_DESD	5
#define TRUE		1
#define FALSE		0
#define MAXNAME		30

typedef struct studentMarkST
{
	union check
	{		
		char u_course[SUBJECT_LEN];
		int i_Module;
	}o_uc;
	
	char c_Name[MAXNAME];		// name of student
	char c_course[SUBJECT_LEN];	// course name
	int  i_Roll;			// roll number
	int  *Marks;			// array of marks
	int  i_Result;			// result of that marks
	
}STDMRK;

/***********************************************************************************
	Function			: print_Marksheet()
	Description			: This function displays the record of student
	Input				: struct **, int
	Output				: nothing

	@Author : Yuvraj Takey
*/
void print_Marksheet(STDMRK **ptr, int i_MaxStud)
{
	int index = 0, j_index = 0, i_Total = 0;
	
	printf("\n----------------------------RESULT--------------------------------\n");
	
	// iterate till number of students
	for(index = 0; index < i_MaxStud; index++)
	{
		// chaeck for invalid course
		if(ptr[index]->o_uc.i_Module != FALSE)
		{
			// display the resord
			printf("Course\t: %s\n",ptr[index]->c_course);
			printf("Name\t: %s\n",ptr[index]->c_Name);
			printf("Roll\t: %d\n",ptr[index]->i_Roll);
		
			// iterare till number of modules for each course
			for(j_index = 0; j_index < (ptr[index]->o_uc.i_Module); j_index++)
			{
				i_Total = i_Total + ptr[index]->Marks[j_index];
			}
			
			// calculate percentage for every student
			printf("Marks\t: %.2f percent\n\n",((float)(i_Total) / (ptr[index]->o_uc.i_Module*100)) * 100);
		}	
		
		i_Total = 0;
	}
	
	// end of execution
	printf("\n-------------------------------------------------------------------\n");

	return ;
}

/***********************************************************************************
	Function			: stud_Marksheet()
	Description			: This function accept the student record
	Input				: struct **, int
	Output				: nothing

	@Author : Yuvraj Takey
*/
void stud_Marksheet(STDMRK **ptr, int i_MaxStud)
{
	int index = 0, j_index = 0;
	
	// accept the course
	printf("Select course as per your choice\n");
	printf("DAC\n");
	printf("DSSD\n");
	printf("DESD\n");	
	
	// iterate till number of students
	for(index = 0; index < i_MaxStud; index++)
	{
		printf("\nKindly enter the course name for student %d\t",index+1);
		scanf("%s",ptr[index]->o_uc.u_course);
	
		// if given course is available then copy it into struct variable and assign the number of modules
		if(strcasecmp(ptr[index]->o_uc.u_course,"DAC") == 0)
		{
			strcpy(ptr[index]->c_course,"DAC");
			ptr[index]->o_uc.i_Module = SUBJECT_DAC;
		}
		else if(strcasecmp(ptr[index]->o_uc.u_course,"DSSD") == 0)
		{
			strcpy(ptr[index]->c_course,"DSSD");
			ptr[index]->o_uc.i_Module = SUBJECT_DSSD;
		}
		else if(strcasecmp(ptr[index]->o_uc.u_course,"DESD") == 0)
		{
			strcpy(ptr[index]->c_course,"DESD");
			ptr[index]->o_uc.i_Module = SUBJECT_DESD;
		}
		else
		{
			// if user given input invalid then dont allocate the memory for marks array
			// here invalid output makes entry as "Not available"
			strcpy(ptr[index]->c_course,"N.A");
			ptr[index]->o_uc.i_Module = FALSE;
		}
		
		// flush buffer
		__fpurge(stdin);
	
		// accept next input, only if course is available in hyderabad center	
		if(ptr[index]->o_uc.i_Module != FALSE)
		{
			// accept name of student
			printf("Kindly enter the name of student %d\t",index+1);
			scanf("%[^'\n']s",ptr[index]->c_Name);
		
			// accept roll number of student
			printf("Kindly enter the roll_No of student %d\t",index+1);
			scanf("%d",&(ptr[index]->i_Roll));
			
			// allocate memory for module_marks
			ptr[index]->Marks = (int*)malloc((ptr[index]->o_uc.i_Module) * sizeof(int));
			
			for(j_index = 0; j_index < (ptr[index]->o_uc.i_Module); j_index++)
			{
				// accept the marks
				printf("Kindly enter the marks for module %d\t",j_index+1);
				scanf("%d",&(ptr[index]->Marks[j_index]));
			}
		}
		else
		{	
			// invalid course
			printf("[SORRY] : your course is not available in our HYD-center\n\n");
		}
	}
	
	return ;
}

//--------------------------------------------------__MAIN__--------------------------------------------//
int main()
{
	int i_MaxStud = 0, index = 0;	
	
	// creating object of structure
	STDMRK o_hyd;
	STDMRK **ptr = NULL;
	
	// accept number of student
	printf("Kindly enter the number of students\n");
	scanf("%d",&i_MaxStud);
	
	// allocate memory dynamically
	ptr = (STDMRK**)malloc(i_MaxStud * sizeof(STDMRK*));
	
	// allocate memkory dynamically for structures
	for(index = 0; index < i_MaxStud; index++)
	{
		ptr[index] = (STDMRK*)malloc(sizeof(STDMRK));
	}
	
	// call to the function that will strore student records
	stud_Marksheet(ptr,i_MaxStud);
	
	// get the marksheet record
	print_Marksheet(ptr,i_MaxStud);
	
	// free the memory of structures
	for(index = 0; index < i_MaxStud; index++)
	{
		free(ptr[index]);
	}
	
	// free double-pointer's memory
	free(ptr);
	
	return 0;
}
