	
/*
 *	Demonstrate Inner class example
 *
 *	@DSSD	- Yuvraj Takey
 */

 import java.lang.*;
 import java.lang.String;

 class Outer
 { 	
 	private int emp_id, emp_sal[], emp_age[];
 	private String emp_nam[];
 	
 	public Outer()
 	{
 		// initialize variables
 		emp_id = 0;
 		emp_nam = new String[5];
 		emp_sal = new int[5];
 		emp_age = new int[5];
 		
 	}
 
 	// method that will setup the Employee Database	
 	public void setupDB()
 	{
 		// employee name
 		emp_nam[0] = "Ram";
 		emp_nam[1] = "Shyam";
 		emp_nam[2] = "Manoj";
 		emp_nam[3] = "Shubham";
 		emp_nam[4] = "Kishor";
 		
 		// employee salary
 		emp_sal[0] = 4200;
 		emp_sal[1] = 4500;
 		emp_sal[2] = 4900;
 		emp_sal[3] = 3900;
 		emp_sal[4] = 4000;
 		
 		// employee age
 		emp_age[0] = 25;
 		emp_age[1] = 26;
 		emp_age[2] = 49;
 		emp_age[3] = 21;
 		emp_age[4] = 22;
 	}
 	
 	// Inner class
 	private class Inner
 	{
 		private int e_id;
 		private int e_sal;
 		private int e_age;
 		private String e_nam;
 		
 		public Inner()
 		{
 			// initialize the class variables
 			e_id = e_sal = e_age = 0;
 			e_nam = new String();
 		}
 		
 		public void showEmp_Details()
 		{
 			// check for condition
 			if(this.e_id != 0)
 			{
 				// message
 				System.out.println("Employee ID     :	"+this.e_id);
 				System.out.println("Employee name   :	"+this.e_nam);
 				System.out.println("Employee age    :	"+this.e_age);
 				System.out.println("Employee salary :	"+this.e_sal);
 			}
 			else
 			{
 				System.out.println("[SORRY] : object is empty");
 			}
 		}
 		
 		private void getEmp_Details(int i_id)
 		{
 			// file the details in inner object
 			this.e_id = i_id;
 			this.e_sal = emp_sal[i_id];
 			this.e_age = emp_age[i_id];
 			this.e_nam = emp_nam[i_id];
 		}
 	}// end of Inner class
 	
 	public Outer.Inner getDataById(int i_id)
 	{
 		// create temporary object
 		Outer.Inner in = this.new Inner();
 		
 		// call to method and collect all data into object
 		in.getEmp_Details(i_id);
 		
 		// return the object
 		return in;
 	}
 }

 class InnerEx
 {
	public static void main(String args[])
	{
		System.out.println("Inner Class Example\n");
		
		// creat the object of Outer class
		Outer o = new Outer();
		
		// initiate the DataBase
		o.setupDB();
		
		// get the employee details
		Outer.Inner in = o.getDataById(2);
		
		// print the details
		in.showEmp_Details();		
		/* 	while getting any employee details we do not need to pass whole Outer class object.
		 * 	for that short object i.e Inner Class can sufficient to get the data of perticular employee
		 */
				
	}
 }
 
 
