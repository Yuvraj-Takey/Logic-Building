/*
 * Define a template stack class. Using this template class, create stack object of inr, float, char* and complex type
 * Include exception handling functionalu
 *
 *	@ DSSD
*/

#include <iostream>
using namespace std;
#include <string.h>
#include <stdio_ext.h>
#define RUNNING	1
#define MAXCHAR	50

template<class T, int i_size>
class Stack_C
{
	private:
	int i_Offs;
	T arr[i_size];		// char *arr[10]
	
	public:
	Stack_C();
	void accept_Stack();
	void show_Stack();
	void s_Push(T);
	T s_Pop();
	void operation_Obj();
	void operation_Obj(short);
	~Stack_C();
};

template<class T, int i_size>
Stack_C<T,i_size>::Stack_C()
{
	// flush the memory
	memset(arr,0,i_size*sizeof(T));
	i_Offs = 0;
}

/***********************************************************************************
	Function			: show_Stack()
	Description			: This function displays the stack element
	Input				: nothing
	Return				: nothing

	@author : Yuvraj Takey
*/
template<class T, int i_size>
void Stack_C<T,i_size>::show_Stack()
{
	int index = 0;
	
	cout<<"Stack elements are:"<<endl<<"--->"<<endl;
	
	// iterate till array offset
	for(index = (i_Offs-1); index >= 0; index--)
	{
		cout<<arr[index]<<"  ";
	}
	
	cout<<endl;
	
	return;
}


/***********************************************************************************
	Function			: s_Push()
	Description			: This function pushes the element in stack
	Input				: Template element
	Return				: nothing

	@author : Yuvraj Takey
*/
template<class T, int i_size>
void Stack_C<T,i_size>::s_Push(T ele)
{
	// check for stack limit
	if(i_Offs > (i_size-1))
	{
		cout<<"[SORRY] : stack gets overflow"<<endl;
		return ;
	}
	
	// push the element into stack
	arr[i_Offs] = (T)ele;
	i_Offs++;
	return;
}

/***********************************************************************************
	Function			: s_Pop()
	Description			: This function pop the element from stack
	Input				: nothing
	Return				: Template element

	@author : Yuvraj Takey
*/
template<class T, int i_size>
T Stack_C<T,i_size>::s_Pop()
{
	T temp;
	
	// check for stack limit
	if(i_Offs <= (0))
	{
		cout<<"[SORRY] : stack underflow"<<endl;
		return (temp);
	}
	else
	{
	
		// pop the recent element from stack
		return(arr[--i_Offs]);
	}
}

// Distructor
template<class T, int i_size>
Stack_C<T,i_size>::~Stack_C()
{
	cout<<"In Dist"<<endl;
}

/******************************************************************************************************
	Function			: operation_Obj()
	Description			: This function operform operation using stack class
	Input				: nothing
	Return				: nothing

	@author : Yuvraj Takey
*/
template<class T, int i_size>
void Stack_C<T,i_size>::operation_Obj()
{
	char c_Choice = ' ';
	T t_Value ;
	
	// iterate till exit
	while(RUNNING)
	{
		// menu list
		cout<<"Kindly enter your choice"<<endl;
		cout<<"1. Push\t\t";
		cout<<"2. Pop\t\t";
		cout<<"3. Show\t\t";
		cout<<"4. Exit"<<endl;
		cin>>c_Choice;

		// flush the memory
		__fpurge(stdin);
		
		switch(c_Choice)
		{
			case '1':
			{
				// flush the memory
				__fpurge(stdin);
				
				// accept input for push operation
				cout<<"Enter element"<<endl;
				
				// accept the data from user
				cin>>t_Value;
				
				// calling to the function
				this->s_Push(t_Value);
											
				break;
			}
			
			case '2':
			{
				// call for pop operation
				T element = this->s_Pop();
				//if(element)
				cout<<"Poped element "<<element<<endl;
				break;
			}
			
			case '3':
			{
				// for display the stack element
				this->show_Stack();
				break;
			}
			
			case '4':
			{
				cout<<"Exiting.."<<endl;
				c_Choice = '\a';
				break;
			}
			
			default:
			{
				cout<<"[SORRY] : invalid operation"<<endl;
				break;
			}
		}
		
		// condition for terminate while
		if(c_Choice == '\a')
		{
			break;
		}
	}// end of while
	
	return ;
}

/******************************************************************************************************
	Function			: operation_Obj()	// explicit speliazation
	Description			: This function operform string operation using stack class
	Input				: short
	Return				: nothing

	@author : Yuvraj Takey
*/
template<class T, int i_size>
void Stack_C<T,i_size>::operation_Obj(short i_Len)
{
	char c_Choice = ' ';
	char *c_Buff = NULL;
	
	// iterate till exit
	while(RUNNING)
	{	
		// menu list
		cout<<"Kindly enter your choice"<<endl;
		cout<<"1. Push\t\t";
		cout<<"2. Pop\t\t";
		cout<<"3. Show\t\t";
		cout<<"4. Exit"<<endl;
		cin>>c_Choice;

		// flush the memory
		__fpurge(stdin);
		
		switch(c_Choice)
		{
			case '1':
			{	
				try
				{
					//create dynamic memory allocation
					c_Buff = new char[i_Len];
					
					if(c_Buff == NULL)
					{
						throw ('N');
					}
					
					// flush the memory
					memset(c_Buff,0,i_Len);
				
					// accept input for push operation
					cout<<"Enter element"<<endl;
				
					// accept the data from user
					cin.get(c_Buff,i_Len);
				
					// calling to the function
					this->s_Push(c_Buff);
				}
				catch(char ex)
				{
					cout<<"[SORRY] : failed in memory allocation"<<endl;
				}
				catch(...)
				{
					cout<<"[SORRY] : something went wrong"<<endl;
				}							
				break;
			}
			
			case '2':
			{
				// call for pop operation
				T element = this->s_Pop();
				if(element)
				cout<<"Poped element "<<element<<endl;
				break;
			}
			
			case '3':
			{
				// for display the stack element
				this->show_Stack();
				break;
			}
			
			case '4':
			{
				cout<<"Exiting.."<<endl;
				c_Choice = '\a';
				break;
			}
			
			default:
			{
				cout<<"[SORRY] : invalid operation"<<endl;
				break;
			}
		}
		
		// condition for terminate while
		if(c_Choice == '\a')
		{
			try
			{
				//free the memory which created while accepting string
				for(int i = 0; i < i_Offs; i++)
				{
					delete arr[i];
				}
			}
			catch(...)
			{
				cout<<"[SORRY] : memory deallocation failed"<<endl;
			}
			
			break;
		}
	}// end of while
	
	return ;
}

/******************************************************************************************************
	class				: Complex_Cs
	Description			: This class operform complex operation

	@author : Yuvraj Takey
*/
class Complex_Cs
{
	int i_real;
	int i_img;

	public:	
	Complex_Cs()
	{
		i_real = 0;
		i_img = 0;
	}
	Complex_Cs(int real, int img)
	{
		i_real = real;
		i_img = img;
	}
	
	friend ostream& operator<<(ostream&, Complex_Cs&);
	friend istream& operator>>(istream&, Complex_Cs&);

};

/******************************************************************************************************
	function			: <<()
	Description			: This is operator overloading function for overload cout<< functionality
	input				: ostream&, Complex_Cs&
	Return				: ostream&

	@author : Yuvraj Takey
*/
ostream& operator<<(ostream &cout, Complex_Cs &c_Obj)
{
	cout<<"comlex value : "<<c_Obj.i_real<<", "<<c_Obj.i_img<<"i"<<endl;
	return (cout);
}

/******************************************************************************************************
	function			: >>()
	Description			: This is operator overloading function for overload cin>> functionality
	input				: istream&, Complex_Cs&
	Return				: istream&

	@author : Yuvraj Takey
*/
istream& operator>>(istream &cin, Complex_Cs &c_Obj)
{
	cout<<"Enter the value for real and imaginary"<<endl;
	cin>>c_Obj.i_real>>c_Obj.i_img;
	return (cin);
}

/*=======================================	MAIN	========================================*/

int main()
{
	char c_Choice = ' ';
	
	// iterate till end
	while(RUNNING)
	{
		// menu list
		cout<<"Kindly enter your choice"<<endl;
		cout<<"1.	Integral Stack"<<endl;
		cout<<"2.	Character Stack"<<endl;
		cout<<"3.	Float Stack"<<endl;
		cout<<"4.	Char* Stack"<<endl;
		cout<<"5.	Complex Stack"<<endl;
		cout<<"6.	Exit _: ";
		cin>>c_Choice;

		// user choice
		switch(c_Choice)
		{
			case '1':
			{
				// create the appropriate object and perform operation
				Stack_C <int,10> s_Ob;
				s_Ob.operation_Obj();				
				break;
			}			
			
			case '2':
			{
				// create the appropriate object and perform operation
				Stack_C <char,10> s_Ob;
				s_Ob.operation_Obj();	
				break;
			}
			
			case '3':
			{
				// create the appropriate object and perform operation
				Stack_C <float,10> s_Ob;
				s_Ob.operation_Obj();	
				break;
			}
			
			case '4':
			{
				// create the appropriate object and perform operation
				Stack_C <char*,10> s_Ob;
				s_Ob.operation_Obj(MAXCHAR);	
				break;
			}
			
			case '5':
			{
				// create the appropriate object and perform operation
				Stack_C <Complex_Cs,10> s_Ob;
				s_Ob.operation_Obj();	
				break;
			}
			
			case '6':
			{
				cout<<"Exiting.."<<endl;
				c_Choice = '\a';
				break;
			}
			
			default:
			{
				cout<<"[SORRY] : invalid operation"<<endl;
				break;
			}
		}
		
		// condition for terminate while
		if(c_Choice == '\a')
		{
			// break main while loop
			break;
		}
	}	
	
	return 0;
}
