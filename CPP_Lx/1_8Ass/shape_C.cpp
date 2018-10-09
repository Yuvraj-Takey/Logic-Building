/*
 * Define shape class. Derive Triangle, Square and Rectangle classes. Demonstrate the use of virtual function by including 
 * display_area() as a virtual function
 *
 *	@ DSSD - Yuvraj Takey
 */
 
 #include <iostream>
 using namespace std;
 #define PI		3.142
 #define RUNNING	1
 
 // Shape class
 class Shape_C
 {
 	protected:
 	float f_area_Value;
 	
 	public:
 	float f_rad;
 	float f_len;
 	float f_hei;
 	float f_base;
 	
 	Shape_C()
 	{
 		// initialise all value to default
 		f_rad = 0.0f;
 		f_len = 0.0f;
 		f_hei = 0.0f;
 		f_base = 0.0f;
 		f_area_Value = 0.0f;
 	}
 	
 	// get area from user
 	virtual void get_area()
 	{
 		cout<<"Shape"<<endl;
 	}
 	
 	// display area calculation
 	virtual void display_area()
 	{
 		cout<<"Shape"<<endl;
 	}
 };
 
 // Triangle class inheriting Shape class
 class Triangle_C : public Shape_C
 {
 	public:
 	Triangle_C()
 	{
 		//TR	=> 	0.5(b*h)
 		f_base = 0.0f;
 		f_hei = 0.0f; 		
 	}
 	
 	// get area from user
 	void get_area()
 	{
 		cout<<"Kindly enter the value of base and height"<<endl;
 		cin>>f_base>>f_hei;
 	}
 	
 	// display area calculation
 	void display_area()
 	{
 		// calculate the value
 		f_area_Value = 0.5 * f_base * f_hei;
 		cout<<"Area of Triangle is : "<<f_area_Value<<endl<<endl;
 	}
 	
 };
 
  // Square class inheriting Shape class
 class Square_C : public Shape_C
 {
 	public:
 	Square_C()
 	{
 		//squ	=>	PI*r*r
 		f_rad = 0.0f;
 		f_area_Value = 0.0f;
 	}
 	
 	// get area from user
 	void get_area()
 	{
 		cout<<"Kindly enter the value of radius"<<endl;
 		cin>>f_rad;
 	}
 	
 	// display area calculation
 	void display_area()
 	{
 		// calculate the value
 		f_area_Value = PI * f_rad * f_rad;
 		cout<<"Area of Square is : "<<f_area_Value<<endl<<endl;
 	} 	
 };
 
  // Rectangle class inheriting Shape class
 class Rectangle_C : public Shape_C
 {
 	public:
 	Rectangle_C()
 	{
 		//Rec	=>	l*h
 		f_len = 0.0f;
 		f_hei = 0.0f;
 		f_area_Value = 0.0f;
 	}
 	
 	// get area from user
 	void get_area()
 	{
 		cout<<"Kindly enter the value of length and height"<<endl;
 		cin>>f_len>>f_hei;
 	}
 	
 	// display area calculation
 	void display_area()
 	{
 		// calculate the value
 		f_area_Value = f_len * f_hei;
 		cout<<"Area of Rectangle is : "<<f_area_Value<<endl<<endl;
 	}
 };
 
 int main()
 {
 	char c_Choice = ' ';
 	
 	// create shape pointer
 	Shape_C *p_Shape;
 	
 	while(RUNNING)
 	{
 		// menu
 		cout<<"Kindly select your choice"<<endl;
 		cout<<"1.	Area of Triangle"<<endl;
 		cout<<"2.	Area of Square"<<endl;
 		cout<<"3.	Area of Rectangle"<<endl;
 		cout<<"4.	Exit "<<endl;
 		cin>>c_Choice;
 		
 		switch(c_Choice)
 		{
 			case '1':
 			{
 				//assign object to shape pointer
				p_Shape = new Triangle_C();
				p_Shape->get_area();
				p_Shape->display_area();
 				
 				break;
 			}
 			case '2':
 			{
 				//assign object to shape pointer
				p_Shape = new Square_C();
				p_Shape->get_area();
				p_Shape->display_area();
 				
 				break;
 			}
 			case '3':
 			{
 				//assign object to shape pointer
				p_Shape = new Rectangle_C();
				p_Shape->get_area();
				p_Shape->display_area();
 				
 				break;
 			}
 			case '4':
 			{
 				c_Choice = '\a';
 				break;
 			}
 			default:
 				cout<<"[SORRY] : invalid parameter"<<endl;
 				break;
 		}
 		
 		// Termination condition for while
 		if(c_Choice == '\a')
 		{
 			break;
 		}
 	}
 	
 	
 	// free the memory
 	delete p_Shape;
 	
 	return 0;
 }
