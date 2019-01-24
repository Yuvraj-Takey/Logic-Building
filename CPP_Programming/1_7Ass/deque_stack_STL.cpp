/*
 * Define a double ended queue class. Define a stack class by extending the functionality of double ended queue class. 
 * create object of both the classes and test the functionality
 *
 *	@ DSSD
 */
 
 #include <iostream>
 using namespace std;
 #include <deque>
 #include <stdio.h>
 #include <string.h>
 #define RUNNING	1
 #define D_QUEUE_ST	99
 #define D_QUEUE_INT	98
 #define STACK_INT	182
 #define STACK_ST	183
 
 /***********************************************************************************
	Class			: Deque_C
	Description		: This class contains operation on Deque (using STL)

	@author : Yuvraj Takey
*/
 template <class T>
 class Deque_C
 {
 	public:
 	deque <T> o_DQ;
 	typename std :: deque <T> :: iterator it;
 	
 	// constructor
 	Deque_C()
 	{
 		//code
 	}
 	void insert_First(T i_ele)
 	{
 		// pushing the element at front in Deque
 		o_DQ.push_front(i_ele);
 	
 	}
 	void insert_Last(T i_ele)
 	{
 		// pushing the element at back in deque
		o_DQ.push_back(i_ele);
 	}
 	void delete_First()
 	{
 		if(!o_DQ.empty())
 		{
 			//poping the element from first in deque
 			o_DQ.pop_front();
 		}
 		else
 		{
 			cout<<"[SORRY] : It is underflow"<<endl;
 		}
 	}
 	void delete_Last()
 	{
 		if(!o_DQ.empty())
 		{
 			// poping the element from last in deque
 			o_DQ.pop_back();
 		}
 		else
 		{
 			cout<<"[SORRY] : It is underflow"<<endl;
 		}
 	}
 	void show_Queue()
 	{
 		// check condition
 		if(!o_DQ.empty())
 		{
 			it = o_DQ.begin();
 			
 			// iterate till whole list
 			while(it != o_DQ.end())
 			{
 				// print result
 				cout<<*it<<" ";
 				it = it+1;
 			}
 			cout<<endl;
 		}
 		else
 		{
 			cout<<"Empty"<<endl;
 		} 		
 	} 	
 };
 
  /***********************************************************************************
	Class			: Stack_C
	Description		: This class inheriting the Deque_C class and implementing its functionality

	@author : Yuvraj Takey
*/
 template <class T>
 class Stack_C : public Deque_C <T>
 {
 	public:
 	
 	//constructor
 	Stack_C()
 	{
 		// code	
 	}
 	void push(T ele)
 	{
 		// passing to deque function (inherited)
 		this->insert_Last(ele);
 	}
 	void pop()
 	{
 		// passing to deque function (inherited)
 		this->delete_Last();
 	}
 	void show_Stack()
 	{
 		// passing to deque function (inherited)
 		this->show_Queue();
 	}
 };
 
 /***********************************************************************************
	Class			: STL_C
	Description		: This class is mediator class which will perform opration on data type

	@author : Yuvraj Takey
*/
 template <class T>
 class STL_C
 {
 	public:
 	STL_C()
 	{
 		// default code
 	}
 	
 	void op_DqueueI()
 	{
		char c_Choice = ' ';
	 	T t_Value;
	 
	 	cout<<"Kindly select your choice"<<endl;
	 	
	 	// create object of Queue class
	 	Deque_C <T>o_DC;
	 			
	 	while(RUNNING)
		{
		 	cout<<"1.  Insert_First\t";
			cout<<"3.  Insert_Last"<<endl;
			cout<<"2.  Delete_First\t";
			cout<<"4.  Delete_Last"<<endl<<"_________________________________________"<<endl;
			cout<<"5.  Show\t";
			cout<<"6.  Exit_Op"<<endl;
			cin>>c_Choice;
	
			switch(c_Choice)
			{
				case '1':
				{
					cout<<"Kindly enter the element"<<endl;
				
					// accept value from user
					cin>>t_Value;
				
					// pass it to function
					o_DC.insert_First(t_Value);
					break;
				}
				case '2':
				{
					o_DC.delete_First();
					break;
				}
				case '3':
				{
					cout<<"Kindly enter the element"<<endl;
				
					// accept value from user
					cin>>t_Value;
				
					// pass it to function
					o_DC.insert_Last(t_Value);
					break;
				}
				case '4':
				{
					// call to delete fun
					o_DC.delete_Last();
					break;
				}
				case '5':
				{
					// display queue
					o_DC.show_Queue();
					break;
				}
				case '6':
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
	 void op_DqueueS(short i_size)
 	{
		char c_Choice = ' ';
	 	T t_Value;
	 
	 	cout<<"Kindly select your choice"<<endl;
	 	
	 	// create object of Queue class
	 	Deque_C <T>o_DC;
	 			
	 	while(RUNNING)
		{
		 	cout<<"1.  Insert_First\t";
			cout<<"3.  Insert_Last"<<endl;
			cout<<"2.  Delete_First\t";
			cout<<"4.  Delete_Last"<<endl<<"_________________________________________"<<endl;
			cout<<"5.  Show\t";
			cout<<"6.  Exit_Op"<<endl;
			cin>>c_Choice;
	
			switch(c_Choice)
			{
				case '1':
				{
					cout<<"Kindly enter the element"<<endl;
			
					t_Value = new char[i_size];
					memset(t_Value,0,i_size);
					
					// accept value from user
					cin>>t_Value;
				
					// pass it to function
					o_DC.insert_First(t_Value);
					break;
				}
				case '2':
				{
					o_DC.delete_First();
					break;
				}
				case '3':
				{
					cout<<"Kindly enter the element"<<endl;
				
					t_Value = new char[i_size];
					memset(t_Value,0,i_size);
					
					// accept value from user
					cin>>t_Value;
				
					// pass it to function
					o_DC.insert_Last(t_Value);
					break;
				}
				case '4':
				{
					// call to delete fun
					o_DC.delete_Last();
					break;
				}
				case '5':
				{
					// display queue
					o_DC.show_Queue();
					break;
				}
				case '6':
				{
					c_Choice = '\a';
					break;
				}
			}
		
			// terminate condition for while
			if(c_Choice == '\a')
			{
				// release the memory
				o_DC.it = o_DC.o_DQ.begin();
 			
	 			// iterate till whole list
	 			while(o_DC.it != o_DC.o_DQ.end())
	 			{
	 				// release result
	 				delete *(o_DC.it);
	 				o_DC.it = o_DC.it+1;
	 			}
	 			
				break;
			}
		
		}// end of while	
	 }
	 
	 void op_StackI()
	 {
	 	char c_Choice = ' ';
	 	T t_Value;
	 
	 	cout<<"Kindly select your choice"<<endl;
	 	
	 	//create object of stack class
	 	Stack_C <T>o_ST;
	 			
	 	while(RUNNING)
		{
		 	cout<<"1.  Push\t";
			cout<<"2.  Pop"<<endl;
			cout<<"3.  Show\t";
			cout<<"4.  Exit_Op"<<endl;
			cin>>c_Choice;
		
			switch(c_Choice)
			{
				case '1':
				{
					cout<<"Kindly enter the element"<<endl;
				
					// accept value from user
					cin>>t_Value;
				
					// pass it to function
					o_ST.push(t_Value);
					break;
				}
				case '2':
				{
					// call to pop function
					o_ST.pop();
					break;
				}
				case '3':
				{
					// display stack
					o_ST.show_Stack();
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
	 
	 void op_StackS(short i_size)
	 {
	 	char c_Choice = ' ';
	 	T t_Value;
	 
	 	cout<<"Kindly select your choice"<<endl;
	 	
	 	//create object of stack class
	 	Stack_C <T>o_ST;
	 			
	 	while(RUNNING)
		{
		 	cout<<"1.  Push\t";
			cout<<"2.  Pop"<<endl;
			cout<<"3.  Show\t";
			cout<<"4.  Exit_Op"<<endl;
			cin>>c_Choice;
		
			switch(c_Choice)
			{
				case '1':
				{
					cout<<"Kindly enter the element"<<endl;
				
					t_Value = new char[i_size];
					memset(t_Value,0,i_size);
				
					// accept value from user
					cin>>t_Value;
					
					// pass it to function
					o_ST.push(t_Value);
					break;
				}
				case '2':
				{
					// call to pop function
					o_ST.pop();
					break;
				}
				case '3':
				{
					// display stack
					o_ST.show_Stack();
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
				// release the memory
				o_ST.it = o_ST.o_DQ.begin();
 			
	 			// iterate till whole list
	 			while(o_ST.it != o_ST.o_DQ.end())
	 			{
	 				// release result
	 				delete *(o_ST.it);
	 				o_ST.it = o_ST.it+1;
	 			}
				break;
			}
		
		}// end of while
	 }
 	
 	
 };
 
 
 
 
/************************************************	Mediator Function	************************************/
 
 void operation(short opr)
 { 	
 	switch(opr)
 	{
 		case D_QUEUE_INT:
 		{
 			//Create deque object with integral value
 			STL_C<int> o_DI;
 			o_DI.op_DqueueI();
 			
 			break;
 		}
 		case D_QUEUE_ST:
 		{
 			//Create deque object with string value
 			STL_C<char*> o_DS;
 			o_DS.op_DqueueS(50);
 		
 			break;
 		}
 		case STACK_INT:
 		{
 			//Create stack object with integral value
 			STL_C<int> o_SI;
 			o_SI.op_StackI();
 		
 			break;
 		}
 		case STACK_ST:
 		{
 			//Create stack object with string value
 			STL_C<char*> o_SS;
 			o_SS.op_StackS(50);
 		
 			break;
 		}
 		default:
 		{
 			cout<<"[SORRY] : invalid operation"<<endl;
 		}
 	}
 }
 
 /**********************************************************	MAIN	**************************************************/
 
 int main()
 {
 	char c_Choice = ' ';
 	short s_Oper = 0;
 	
 	while(RUNNING)
 	{
 		// menu
	 	cout<<"Kindly select your choice"<<endl;
	 	cout<<"1.	Operation D-Queue"<<endl;
	 	cout<<"2.	Operation Stack"<<endl;
	 	cout<<"3.	Exit"<<endl;
	 	
	 	cin>>c_Choice;
	 	
	 	// set flag for exact operation
	 	s_Oper = s_Oper + c_Choice;
	 	
	 	switch(c_Choice)
	 	{
	 		case '1':
	 		{
	 			cout<<"Select your type"<<endl;
	 			cout<<"1.  Integer D-Queue\t";
				cout<<"2.  String D-Queue"<<endl;
 				cin>>c_Choice;
 				
 				s_Oper = s_Oper + c_Choice;
	 			
	 			// calling function for D-Queue operation
	 			operation(s_Oper);
	 			break;
	 		}
	 		case '2':
	 		{
	 			cout<<"Select your type"<<endl;
	 			cout<<"1.  Integer Stack\t";
				cout<<"2.  String Stack"<<endl;
 				cin>>c_Choice;
 				
 				// flags for switch case
 				s_Oper = s_Oper + c_Choice + 'S';
	 			
	 			// caling function for stack operation
	 			operation(s_Oper);
	 			break;
	 		}
	 		case '3':
	 		{
	 			c_Choice = '\a';
	 			break;
	 		}
	 		default:
	 		{
	 			cout<<"[SORRY] : invalid input"<<endl;
	 			break;
	 		}
	 	}
	 	
	 	// terminating condition for while
	 	if(c_Choice == '\a')
	 	{
	 		break;
	 	}
	 	
	 	// reset the flag
	 	s_Oper = 0;
	 	
	}// end of while
	
 	return 0;
 }
