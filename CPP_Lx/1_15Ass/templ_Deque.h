/*
 * Define a template as double ended queue (deque). Drive template stack and queue classes from it.
 * Test is for int and char* type of object
 *
 *	@ DSSD
*/

#include <iostream>
using namespace std;
#include <string.h>
#include <stdio_ext.h>

namespace d_queue
{	
	#define RUNNING	1
	#define MAXCHAR	50
	#define L_EMPTY	0

	template <class T, int i_Size>
	class Deque_C
	{
		protected:
		T arr[i_Size];
		int s_Offs;
		int l_Offs;
	
	
		public:
		Deque_C();
		Deque_C(T);
		void show_Deque();
		void insert_First(T);
		void insert_Last(T);
		T delete_First();
		T delete_Last();
		void operation_Obj();
		void operation_Obj(short);
		~Deque_C();
	};

	// default constructor
	template <class T, int i_Size>
	Deque_C<T,i_Size>::Deque_C()
	{
		// flush the memory
		memset(arr,0,i_Size*sizeof(T));
		s_Offs = 0;
		l_Offs = 0;
	}

	/***********************************************************************************
		Function			: show_Deque()
		Description			: This function display the double ended queue to user 
		Input				: nothing
		Return				: nothing

		@author : Yuvraj Takey
	*/
	template <class T, int i_Size>
	void Deque_C<T,i_Size>::show_Deque()
	{
		int index = 0;
	
		if((s_Offs == L_EMPTY) && (l_Offs == L_EMPTY))
		{
			cout<<"[SORRY] : Empty"<<endl;
			return;
		}
		
		cout<<"Your Result --->  ";
	
		// iterate till D_Queue
		for(index = s_Offs; index < l_Offs; index++)
		{
			cout<<arr[index]<<" ";
		}
	
		cout<<endl;
	
		return ;
	}

	/***********************************************************************************
		Function			: insert_First()
		Description			: This function inserts element at first in Deque
		Input				: template
		Return				: nothing

		@author : Yuvraj Takey
	*/
	template <class T, int i_Size>
	void Deque_C<T,i_Size>::insert_First(T ele)
	{
		int index= 0;
	
		// first element
		if(l_Offs == s_Offs)
		{
			// insert the element in the Deque
			arr[s_Offs] = ele;
		
			// increment last offset (for identify end of deque)
			l_Offs++;
		}
		else
		{
			// iterate till all element not get shifetd
			for(index = l_Offs; ((index > s_Offs) && (i_Size != l_Offs)); index--)
			{
				arr[index] = arr[index-1];
			}
	
			// check for, no loop iterate on above
			if(index != l_Offs)
			{
				// insert the element in the Deque
				arr[index] = ele;
		
				// increment last offset (for identify end of deque)
				l_Offs++;
			}
		}
	}

	/***********************************************************************************
		Function			: delete_First()
		Description			: This function deletes the element from first in Deque
		Input				: nothing
		Return				: template

		@author : Yuvraj Takey
	*/
	template <class T, int i_Size>
	T Deque_C<T,i_Size>::delete_First()
	{
		int index= 0;
		T i_Value = arr[0];		// store that element which is going to be delete
	
		if(l_Offs == L_EMPTY)
		{
			cout<<"[SORRY] :It is empty"<<endl;
			return i_Value;
		}
		
		// iterate till all element not get shifetd
		for(index = s_Offs; index < l_Offs; index++)
		{
			arr[index] = arr[index+1];
		}
	
			// decrement last offset (for identify end of deque)
		if(index != s_Offs)
		{
			l_Offs--;
			return i_Value;
		}
	
		return i_Value;
	}

	/***********************************************************************************
		Function			: insert_Last()
		Description			: This function inserts element at last in Deque
		Input				: template
		Return				: nothing

		@author : Yuvraj Takey
	*/
	template <class T, int i_Size>
	void Deque_C<T,i_Size>::insert_Last(T ele)
	{
		int index= 0;
	
		if(l_Offs == i_Size)
		{
			cout<<"[SORRY] : It is full"<<endl;
			return ;
		}
	
		// first element
		if(l_Offs == L_EMPTY)
		{
			// insert the element in the Deque
			arr[s_Offs] = ele;
		
			// increment last offset (for identify end of deque)
			l_Offs++;
		}
		else
		{
			// insert that element at last
			arr[l_Offs] = ele;
		
			// increment the last offset
			l_Offs++;
		}
	}

	/***********************************************************************************
		Function			: delete_Last()
		Description			: This function deletes element at last in Deque
		Input				: nothing
		Return				: template

		@author : Yuvraj Takey
	*/
	template <class T, int i_Size>
	T Deque_C<T,i_Size>::delete_Last()
	{
		int index= 0;
		T i_Value;
	
		if(l_Offs == s_Offs)
		{
			cout<<"[SORRY] : It is empty"<<endl;
			return i_Value;
		}
	
		// decrement the last offset
		l_Offs--;
	
		//store element
		i_Value = arr[l_Offs];
	
		//remove last element
		arr[l_Offs] = 0;	
	
		return i_Value;
	}

	/***********************************************************************************
		Function			: operation_Obj()
		Description			: This function performs operation on Deque
		Input				: nothing
		Return				: nothing

		@author : Yuvraj Takey
	*/
	template <class T, int i_Size>
	void Deque_C<T,i_Size>::operation_Obj()
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
					this->insert_First(t_Value);
					break;
				}
				case '2':
				{
					this->delete_First();
					break;
				}
				case '3':
				{
					cout<<"Kindly enter the element"<<endl;
				
					// accept value from user
					cin>>t_Value;
				
					// pass it to function
					this->insert_Last(t_Value);
					break;
				}
				case '4':
				{
					this->delete_Last();
					break;
				}
				case '5':
				{
					this->show_Deque();
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


	/***********************************************************************************
		Function			: operation_Obj()	// overloaded
		Description			: This function performs operation on Deque using string
		Input				: short
		Return				: nothing

		@author : Yuvraj Takey
	*/
	template <class T, int i_Size>
	void Deque_C<T,i_Size>::operation_Obj(short s_len)
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
				
					// allocate memory 
					t_Value = new char[s_len];
				
					// accept value from user
					cin>>t_Value;
				
					// pass it to function
					this->insert_First(t_Value);
					break;
				}
				case '2':
				{
					this->delete_First();
					break;
				}
				case '3':
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
				case '4':
				{
					this->delete_Last();
					break;
				}
				case '5':
				{
					this->show_Deque();
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
				// free the allocated memory
				for(s_len = 0; s_len < l_Offs; s_len++)
				{
					delete arr[s_len];
				}
			
				break;
			}
		
		}// end of while
	}


	// class destructor
	template <class T, int i_Size>
	Deque_C<T,i_Size>::~Deque_C()
	{
		cout<<"In Dist"<<endl;
	}
}
