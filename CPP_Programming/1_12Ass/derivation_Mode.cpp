/*
 * develop a class hierarchy and understand the visibility modes of member derived from base class through various derivation
 * (public, private, protected) modes
 *
 *	@ DSSD
 */

 #include <iostream>
 using namespace std;
 
 class Base_C
 {	
 	private:
 	int i_Private;
 	
 	protected:
 	int i_Protected;
 
 	public:
 	int i_Public;
 		
 	Base_C()
 	{
 		i_Public = 10;
 		i_Protected = 20;
 		i_Private = 30;
 	}
 };
 
 // inherited with public derivation mode
 class Derived_C1 : public Base_C
 {
 	public:
 	void d1_Access()
 	{
 		cout<<endl<<"Derived Class 1	: Public inherit"<<endl;
 		cout<<"Public\t\t"<<i_Public<<endl;
 		cout<<"Protected\t"<<i_Protected<<endl;
 	//	cout<<"Private\t\t"<<i_Private<<endl;		// Not Allow
 	}
 };
 
 // inherited with protected derivation mode
 class Derived_C2 : protected Base_C
 {
 	public:
 	void d2_Access()
 	{
 		cout<<endl<<"Derived Class 2	: Protected inherit"<<endl;
 		cout<<"Public\t\t"<<i_Public<<endl;
 		cout<<"Protected\t"<<i_Protected<<endl;
 	//	cout<<"Private\t\t"<<i_Private<<endl;		// Not Allow
 	}
 };
 
 // inherited with private derivation mode
 class Derived_C3 : private Base_C
 {
 	public:
 	void d3_Access()
 	{
 		cout<<endl<<"Derived Class 3	: Private inherit"<<endl;
 		cout<<"Public\t\t"<<i_Public<<endl;
 		cout<<"Protected\t"<<i_Protected<<endl;
 	//	cout<<"Private\t\t"<<i_Private<<endl;		// Not Allow
 	}
 };
 
 // this class inherits that class, which inherits Base_C as private mode
 class Derived_C4 : private Derived_C3
 {
 	public:
 	void d4_Access()
 	{
 		cout<<endl<<"Derived Class 4"<<endl;
 		cout<<"This class inherits that class, which inherits Base_C as private mode"<<endl;
 		cout<<"Result : Blocking inheritance level"<<endl<<endl;
 	//	cout<<"Public\t\t"<<i_Public<<endl;		// Not Allow
 	//	cout<<"Protected\t"<<i_Protected<<endl;		// Not Allow
 	//	cout<<"Private\t\t"<<i_Private<<endl;		// Not Allow
 	}
 };

 
 int main()
 {
 	Derived_C1 o_C1;	// object of derived class 1
 	o_C1.d1_Access();
 	Derived_C2 o_C2;	// object of derived class 2
 	o_C2.d2_Access();
 	Derived_C3 o_C3;	// object of derived class 3
 	o_C3.d3_Access();
 	Derived_C4 o_C4;	// object of derived class 4
 	o_C4.d4_Access();
 
 	return 0;
 }
