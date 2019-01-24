/*
 * Demonstrate the use of virtual destructor with an example class hierarchy
 *
 *	@ DSSD - Yuvraj Takey
 */

#include <iostream>
using namespace std;

class Grand_C
{
	public:
	Grand_C()
	{
		cout<<"Class constructor \t: Grand"<<endl;
	}
	
	// Tell that, this is virtual do not execute yet
	virtual ~Grand_C()
	{
		cout<<"Class destructor \t: Grand"<<endl;
	}
};

// inherit Grand class
class Parent_C : public Grand_C
{
	public:
	Parent_C()
	{
		cout<<"Class constructor \t: Parent"<<endl;
	}
	
	// here by defalut VTABLE gets inherited with VPTR, so do not need to mention virtual again
	~Parent_C()
	{
		cout<<"Class destructor \t: Parent"<<endl;
	}
};

// inherit parent class
class Child_C : public Parent_C
{
	public:
	Child_C()
	{
		cout<<"Class constructor \t: Child"<<endl;
	}
	~Child_C()
	{
		cout<<"Class destructor \t: Child"<<endl;
	}
}; 
 int main()
 {
 	// create one class pointer
 	Grand_C *p_GC;
 	
 	// creating object dynamically	// just because, virtual functionality will be achived on runtime
 	p_GC = new Child_C();
 	
 	// free the allocated resources
 	delete p_GC;	
 	
 	return 0;
 }
