/*
 * Develop a class hierarchy and demonstrate the usage of constructors in base and derived class
 *
 *	@ DSSD
 */
 
 #include <iostream>
 using namespace std;
 
 class Base_C
 {
 	protected:
 	int b_Val;
 	
 	public:
 
 	// Child class constructor will call Parent class constructor insternally like => Parend p;
 	// but assume there is no default constructor here, hence it will throw an error 
 	// check error -
 /*	Base_C()
 	{
 		// here you have to initialise the default value for class data member,
 		// otherwise Child will inherit Parent's garbage value
 	}
 */	
 
 	// parameterised constructor
 	Base_C(int x)
 	{
 		b_Val = x;	
 	}
 
 	// get class data member value	
 	void getBase()
 	{
 		cout<<"The value of base class data member is : "<<b_Val<<endl;
 	}
 };
 
 class Derived_C : public Base_C
 {
 	int d_Val;
 	
 	public:
 	Derived_C()
 	{
 		// initialise default value to class data member
		d_Val = 10;	
 	}
 	
 	// get class data member value
 	void getDerived()
 	{
 		cout<<"from Derived -"<<endl;
 		cout<<"The value of base class data member is : "<<b_Val<<endl;
 	}
 };
 
 
 int main()
 {
 	//create the object of derived class
 	Derived_C o_DC;
 	o_DC.getDerived();	
 	
 	return 0;
 }
