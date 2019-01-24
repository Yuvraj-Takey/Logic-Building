/* Write a program to perform operations on complex numbers.
 *
 * @Author - Yuvraj Takey
 *
 */


#include <stdio.h>
#define RUNNING 1

enum Menu {add = 1,sub,mult,div,end};

/***********************************************************************************
	Function			: add_Complex
	Description			: This function performs addition of complex numbers 
	Input				: int, int, int, int
	Output				: Nothing

	@Author : Yuvraj Takey
*/
void add_Complex(float real1, float img1, float real2, float img2)
{
	printf("\nAddition of given complex number is \t\t: (%.3f) (%.3f)i\n",(float)(real1+real2),(float)(img1+img2));
	return ;
}

/***********************************************************************************
	Function			: sub_Complex
	Description			: This function performs substraction of complex numbers 
	Input				: int, int, int, int
	Output				: Nothing

	@Author : Yuvraj Takey
*/
void sub_Complex(float real1, float img1, float real2, float img2)
{
	printf("\nSubstraction of given complex number is \t: (%.3f) (%.3f)i\n",(float)(real1-real2),(float)(img1-img2));
	return ;
}


/***********************************************************************************
	Function			: mult_Complex
	Description			: This function performs multiplication of complex numbers 
	Input				: int, int, int, int
	Output				: Nothing

	@Author : Yuvraj Takey
*/
void mult_Complex(int real1, int img1, int real2, int img2)
{
	int c_real = 0, c_img = 0;
	
	c_real = (real1 * real2) - (img1 * img2);
	c_img = (real1 * img2) + (img1 * real2);

	printf("\nMultiplication of given complex number is \t: (%d) (%d)i\n",c_real,c_img);
	return ;
}

/***********************************************************************************
	Function			: div_Complex
	Description			: This function performs division of complex numbers 
	Input				: int, int, int, int
	Output				: Nothing

	@Author : Yuvraj Takey
*/
void div_Complex(int real1, int img1, int real2, int img2)
{
	float c_real = 0, c_img = 0;
	
	c_real = (float)(real1 * real2 + img1 * img2) / (real2 * real2 + img2 * img2);
	c_img = (float)(img1 * real2 - real1 * img2) / (real2 * real2 + img2 * img2);

	printf("\nDivision of given complex number is \t\t: (%.3f) (%.3f)i\n",c_real,c_img);
	return ;
}



/******************************		MAIN		**********************************/

int main()
{
	enum Menu select;
	float i_real1 = 0, i_real2 = 0, i_img1 = 0, i_img2 = 0;
	short i_choice = 0;
	
	printf("Enter the values for first complex\n");
	scanf("%f%f",&i_real1,&i_img1);
	
	printf("Enter the values for second complex\n");
	scanf("%f%f",&i_real2,&i_img2);
	
	printf("------\n1st complex : %f_%fi\n2nd complex : %f_%fi\n------\n",i_real1,i_img1,i_real2,i_img2);	
	
	while(RUNNING)
	{
		// menu driven
		printf("\n1.	addition of complex\n");
		printf("2.	substraction of complex\n");
		printf("3.	multiplication of complex\n");
		printf("4.	division of complex\n");
		printf("5.	end operation\n");
		printf("Select your choice_\t");

		// accept menu choice
		scanf("%hi",&i_choice);
		select = i_choice;

		if(select == end)
		{
			break;
		}

		// enum check
		switch(select)
		{
			case add:
			{
				add_Complex(i_real1,i_img1,i_real2,i_img2);	// addition of complex numbers
				break;
			}
			
			case sub:
			{
				sub_Complex(i_real1,i_img1,i_real2,i_img2);	// substraction of complex numbers
				break;
			}
			case mult:
			{
			
				mult_Complex(i_real1,i_img1,i_real2,i_img2);	// multiplication of complex numbers
				break;
			}
			
			case div:		
			{
					div_Complex(i_real1,i_img1,i_real2,i_img2);	// division of complex numbers
					break;
			}
			default:
			{
					printf("[SORRY] : invaliid number\n");
					break;
			}
		}
	}
	
	return 0;
}

