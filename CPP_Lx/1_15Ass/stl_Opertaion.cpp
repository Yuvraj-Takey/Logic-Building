#include <iostream>
using namespace std;
#include "templ_Deque.h"
using namespace d_queue;

#define RUNNING	1

template <class T, int i_Size>
class Stack_Cs : public Deque_C<T,i_Size>
{
	public:
	void operation_Obj();
	void operation_Obj(short);
	
};

/***********************************************************************************
	Function			: operation_Obj()
	Description			: This function performs operation on stack
	Input				: nothing
	Return				: nothing

	@author : Yuvraj Takey
*/
template <class T, int i_Size>
void Stack_Cs<T,i_Size>::operation_Obj()
{
	char c_Choice = ' ';
	T t_Value;
	
	//iterate till terminate
	while(RUNNING)
	{
		//flush buffer
		__fpurge(stdin);
		
		//menu
		cout<<"\nKindly select your choice"<<endl;
		cout<<"1.  Push\t";
		cout<<"2.  Pop"<<endl;
		cout<<"3.  Show\t";
		cout<<"4.  Exit"<<endl;
		
		cin>>c_Choice;
		
		switch(c_Choice)
		{
			case '1':
			{
				cout<<"Kindly enter the element"<<endl;
			
				// accept value from user
				cin>>t_Value;
			
				// pass it to function
				this->insert_Last(t_Value);
				break;
			}
			case '2':
			{
				this->delete_Last();
				break;
			}
			case '3':
			{			
				// call to function
				this->show_Deque();
				break;
			}
			case '4':
			{
				c_Choice = '\a';
				break;
			}
		}
	
		// terminate condition for while
		if(c_Choice == '\a')
		{
			break;
		}
	
	}// end of while	
}

/***********************************************************************************
	Function			: operation_Obj()
	Description			: This function performs operation on stack using string
	Input				: short
	Return				: nothing

	@author : Yuvraj Takey
*/
template <class T, int i_Size>
void Stack_Cs<T,i_Size>::operation_Obj(short s_len)
{
	char c_Choice = ' ';
	T t_Value;
	
	//iterate till terminate
	while(RUNNING)
	{
		//flush buffer
		__fpurge(stdin);
		
		//menu
		cout<<"\nKindly select your choice"<<endl;
		cout<<"1.  Push\t";
		cout<<"2.  Pop"<<endl;
		cout<<"3.  Show\t";
		cout<<"4.  Exit"<<endl;
		
		cin>>c_Choice;
		
		switch(c_Choice)
		{
			case '1':
			{
				cout<<"Kindly enter the element"<<endl;
			
				// allocate memory 
				t_Value = new char[s_len];
				
				// accept value from user
				cin>>t_Value;
			
				// pass it to function
				this->insert_Last(t_Value);
				break;
			}
			case '2':
			{
				this->delete_Last();
				break;
			}
			case '3':
			{			
				// call to function
				this->show_Deque();
				break;
			}
			case '4':
			{
				c_Choice = '\a';
				break;
			}
		}
	
		// terminate condition for while
		if(c_Choice == '\a')
		{
			// free the allocated memory
			for(s_len = 0; s_len < this->l_Offs; s_len++)
			{
				delete this->arr[s_len];
			}
			
			break;
		}
	
	}// end of while	
}

template <class T, int i_Size>
class Queue_Cs : public Deque_C<T,i_Size>
{
	public:
	void operation_Obj();
	void operation_Obj(short);
	
};
/***********************************************************************************
	Function			: operation_Obj()
	Description			: This function performs operation on queue
	Input				: nothing
	Return				: nothing

	@author : Yuvraj Takey
*/
template <class T, int i_Size>
void Queue_Cs<T,i_Size>::operation_Obj()
{
	char c_Choice = ' ';
	T t_Value;
	
	//iterate till terminate
	while(RUNNING)
	{
		//flush buffer
		__fpurge(stdin);
		
		//menu
		cout<<"\nKindly select your choice"<<endl;
		cout<<"1.  Enque\t";
		cout<<"2.  Deque"<<endl;
		cout<<"3.  Show\t";
		cout<<"4.  Exit"<<endl;
		
		cin>>c_Choice;
		
		switch(c_Choice)
		{
			case '1':
			{
				cout<<"Kindly enter the element"<<endl;
			
				// accept value from user
				cin>>t_Value;
			
				// pass it to function
				this->insert_Last(t_Value);
				break;
			}
			case '2':
			{
				this->delete_First();
				break;
			}
			case '3':
			{			
				// call to function
				this->show_Deque();
				break;
			}
			case '4':
			{
				c_Choice = '\a';
				break;
			}
		}
	
		// terminate condition for while
		if(c_Choice == '\a')
		{
			break;
		}
	
	}// end of while	
}

/***********************************************************************************
	Function			: operation_Obj()
	Description			: This function performs operation on queue using string
	Input				: short
	Return				: nothing

	@author : Yuvraj Takey
*/
template <class T, int i_Size>
void Queue_Cs<T,i_Size>::operation_Obj(short s_len)
{
	char c_Choice = ' ';
	T t_Value;
	
	//iterate till terminate
	while(RUNNING)
	{
		//flush buffer
		__fpurge(stdin);
		
		//menu
		cout<<"\nKindly select your choice"<<endl;
		cout<<"1.  Enque\t";
		cout<<"2.  Deque"<<endl;
		cout<<"3.  Show\t";
		cout<<"4.  Exit"<<endl;
		
		cin>>c_Choice;
		
		switch(c_Choice)
		{
			case '1':
			{
				cout<<"Kindly enter the element"<<endl;
			
				// allocate memory 
				t_Value = new char[s_len];
				
				// accept value from user
				cin>>t_Value;
			
				// pass it to function
				this->insert_Last(t_Value);
				break;
			}
			case '2':
			{
				this->delete_First();
				break;
			}
			case '3':
			{			
				// call to function
				this->show_Deque();
				break;
			}
			case '4':
			{
				c_Choice = '\a';
				break;
			}
		}
	
		// terminate condition for while
		if(c_Choice == '\a')
		{
			// free the allocated memory
			for(s_len = 0; s_len < this->l_Offs; s_len++)
			{
				delete this->arr[s_len];
			}
			
			break;
		}
	
	}// end of while	
}


//=================================================================================================================
/********************************************************************************************************
	class			: STL_Op
	Description			: This class performs operation on following Data Structure

	@author : Yuvraj Takey
*/
class STL_Op
{
	public:
	void op_Stack()
	{
		char c_Choice = ' ';	

		while(RUNNING)
		{
			cout<<"\nKindly select your choice"<<endl;
			cout<<"1.	Integer Stack"<<endl;
			cout<<"2.	Char Pointer Stack"<<endl;
			cout<<"3.	Exit_Op"<<endl;
			cin>>c_Choice;
		
			switch(c_Choice)
			{
				case '1':
				{
					Stack_Cs <int,10> i_ST;
					i_ST.operation_Obj();

					break;
				}
				case '2':
				{
					Stack_Cs <char*,10> p_ST;
					p_ST.operation_Obj(50);
					break;
				}
				case '3':
				{
					c_Choice = '\a';
					break;
				}
			}
		
			// terminate condition for while
			if(c_Choice == '\a')
			{
				break;
			}
		
		} // end of while
	}
	
	// operation Queue
	void op_Queue()
	{
		char c_Choice = ' ';	

		while(RUNNING)
		{
			cout<<"\nKindly select your choice"<<endl;
			cout<<"1.	Integer Queue"<<endl;
			cout<<"2.	Char Pointer Queue"<<endl;
			cout<<"3.	Exit_Op"<<endl;
			cin>>c_Choice;
		
			switch(c_Choice)
			{
				case '1':
				{
					Queue_Cs <int,10> i_Qu;
					i_Qu.operation_Obj();

					break;
				}
				case '2':
				{
					Queue_Cs <char*,10> p_Qu;
					p_Qu.operation_Obj(50);
					break;
				}
				case '3':
				{
					c_Choice = '\a';
					break;
				}
			}
		
			// terminate condition for while
			if(c_Choice == '\a')
			{
				break;
			}
		
		} // end of while
	}
};

/****************************************	MAIN	************************************************/

int main()
{
	char c_Choice = ' ';
	
	while(RUNNING)
	{
		cout<<"Perform operation on Data Structure"<<endl;
		cout<<"Kindly enter your choice"<<endl;
		cout<<"1.	Stack"<<endl;
		cout<<"2.	Queue"<<endl;
		cout<<"3.	Exit"<<endl;
		cin>>c_Choice;
		
		switch(c_Choice)
		{
			case '1':
			{
				// create object for stack operation
				STL_Op stl_obj;
				stl_obj.op_Stack();
				break;
			}
			case '2':
			{
				// create object for queue operation
				STL_Op stl_obj;
				stl_obj.op_Queue();
				break;
			}
			case '3':
			{
				c_Choice = '\a';
				break;
			}
			default:
			{
				cout<<"[SORRY] : Invalid input"<<endl;
			}
		}
		
		//terminating while
		if(c_Choice == '\a')
		{
			cout<<"Goodbye"<<endl;
			break;
		}
	}// end of while
	
	
	return 0;
}
