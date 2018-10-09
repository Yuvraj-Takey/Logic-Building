/*
 * Define a point class, where each object represents point in cartesian coordinate(x,y)
 * Define object of the class and calculate the distance between the 2 points through friend function
 *
 *	@ DSSD - Yuvraj Takey
*/

#include <iostream>
using namespace std;
#include <math.h>
#define MAXARR	10

class Point_Cs
{
	private:
	int i_x, i_y;
	
	public:
	Point_Cs();
	Point_Cs(int, int);
	void get_Point();
	
	friend float cal_Dist(Point_Cs, Point_Cs);
};

// default constructor
Point_Cs::Point_Cs()
{
	i_x = 0;
	i_y = 0;
}

// parameterised constructor
Point_Cs::Point_Cs(int x, int y)
{
	i_x = x;
	i_y = y;
}

/***********************************************************************************
	Function			: get_Point()
	Description			: This function accepts the x,y coordinate from user
	Input				: nothing
	Return				: nothing

	@author : Yuvraj Takey
*/
void Point_Cs::get_Point()
{
	cout<<"Kindly enter the value of x and y coordinate"<<endl;
	cin>>i_x>>i_y;
	
	return ;
}

/***********************************************************************************
	Function			: cal_Dist()	// necked function
	Description			: This function calculates distance between 2 points
	Input				: Point_Cs,Point_Cs
	Return				: float

	@author : Yuvraj Takey
*/
float cal_Dist(Point_Cs point1, Point_Cs point2)
{
	float i_Dist = 0;
	
	// calculate distance formulae
	i_Dist = sqrt( ((point2.i_x - point1.i_x)*(point2.i_x - point1.i_x)) + ((point2.i_y - point1.i_y)*(point2.i_y - point1.i_y)) );
	
	return i_Dist;
}

//---------------------------------------------------------------------------------------------------------------

int main()
{
	Point_Cs p_Ob1,p_Ob2;
	
	p_Ob1.get_Point();
	p_Ob2.get_Point();

	cout<<"Your result is : "<<cal_Dist(p_Ob1,p_Ob2)<<endl;
			
	return 0;
}
