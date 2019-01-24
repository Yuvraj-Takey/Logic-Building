/*
 * Demonstrate the use of virtual base class
 *
 *	
 *	@ DSSD - Yuvraj Takey
 */
 
 #include <iostream>
 using namespace std;
 
 class Grand_C
 {
 	public:
 	int i_Value;
 	
 	Grand_C()
 	{
 		i_Value = 10;
 	}
 	Grand_C(int index)
 	{
 		i_Value = index;
 		cout<<"Cons G\t: "<<index<<endl;
 	}
 	
 	void get_Value()
 	{
 		cout<<"Grand value \t: "<<i_Value<<endl;
 	}
 };
 
 // inherits parent virtually
 class Parent_C1 : virtual public Grand_C
 {
 	public:
 	
 	Parent_C1()
 	{
 		i_Value++;
 	}
 	Parent_C1(int a, int b)
 	{
 		cout<<"Cons p1\t: "<<a<<" "<<b<<endl;
 	}
 	
 	void get_Value()
 	{
 		cout<<"Parent value 1 \t: "<<i_Value<<endl;
 	}
 };
 
 // inherits parent virtually
 class Parent_C2 : virtual public Grand_C
 {
 	public:
 	
 	Parent_C2()
 	{
 		// code
 	}
 	Parent_C2(int a, int b)
 	{
 		cout<<"Cons p2\t: "<<a<<" "<<b<<endl;
 	}
 	
 	void get_Value()
 	{
 
 		cout<<"Parent value 2 \t: "<<i_Value<<endl;
 	}
 };
 
 // inherits 2 virtual parents into child class (diamond)
 class Child_C : public Parent_C1, public Parent_C2
 {
 	public:
 	
 	Child_C()
 	{
 		i_Value++;
 	}
 	
 	// creating parameterised constructor and passing parameter to parent class
 	Child_C(int a,int b,int c):Parent_C1(a,b),Parent_C2(a,c),Grand_C(a)
 	{
 		cout<<"Cons C\t: "<<a<<" "<<b<<" "<<c<<" "<<endl<<endl;
 	}
 	
 	void get_Value()
 	{
 		cout<<"Child value \t: "<<i_Value<<endl;
 	}
 };
 
 int main()
 {
 	Child_C obj(10,20,30);
 	obj.get_Value();
 	
 	return 0;
 }
