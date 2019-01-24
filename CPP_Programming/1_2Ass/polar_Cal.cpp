/*
 * Define polar class where each object represents point in polar coordinate (angle and radius)
 * Include static data member which keeps track the number of active object of the class
 *
 *	@ DSSD - Yuvraj Takey
 */
 
 #include <iostream>
 using namespace std;
 #include <math.h>
 
 class Polar_Cs
 {
 	private:
 	int i_angle, i_radius;
 	
 	public:
 	static short i_active;

 	Polar_Cs();
 	Polar_Cs(int, int);
 	void get_Value();
 	~Polar_Cs();
 };
 
 short Polar_Cs::i_active = 0;
 
 // default constructor
 Polar_Cs::Polar_Cs()
 {
 	i_angle = 0;
 	i_radius = 0;
 	i_active++;
 }
 
  // parameterised constructor
 Polar_Cs::Polar_Cs(int i_agl, int i_rad)
 {
 	i_angle = i_agl;
 	i_radius = i_rad;
 	i_active++;
 }
 
 
 // distructor
 Polar_Cs::~Polar_Cs()
 {
 	i_active--;
 }


//--------------------------------------	MAIN	------------------------------------------------------ 

 int main()
 {
 	Polar_Cs p_Obj1(9,11), p_Obj2, p_Obj3, p_Obj4(10,50), p_Obj5(2,5);
 
 	cout<<"Number of active objects are : "<<Polar_Cs::i_active<<endl;	
 	
 	return 0;
 }
