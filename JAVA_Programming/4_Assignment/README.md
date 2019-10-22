# Experiments


1. Define a base class person and a derived class employee with single inheritance.
-Define SetData() member functions in each of the class with different
signatures to set the data members and demonstrate overloading of member
functions.
-Define GetData() member functions in each of the class with same signatures
to display data and demonstrate overriding of member functions.

2. Modify program 1 to define a parametrized constructor and finalizer in each
class. Demonstrate calling the constructor of the base class from the constructor
of the derived class.
-Create objects of person and employee classes to show the order of
invocation of constructors.

3. Modify program 2 to define another class manager that derives from employee, to
create a chain of multilevel hierarchy.(manager inherits from employee & employee
inherits from person)
-Create objects of person, employee, and manager classes to show the order of
invocation of constructors.

4. Modify program 2 to define another class student that derives from person, to
create a hierarchial inheritance.(employee and student inherit from person)
-Create objects of person, employee, and student classes to show the order of
invocation of constructors.

5. Write a java file Person.java containing definition of independent class Person
in package com.person, and another java file Address.java containing definition of
independent class Address in com.address package.
-Write a container class employee that has a person and an address object as
contained data members (besides other data members) by importing the above
packages.
-Demonstrate the passing of arguments in the constructors of person and
address classes by the constructor of the employee class.

6. Rework program 5 to use both inheritance and containership. The employee class
inherits from person class and acts as a container class for address class object.

7. Write a program to demonstrate the use of try, catch, finally throw and throws
keywords and demonstrate the following points in the program.
a) Multiple catch blocks.
b) try-catch-finally combination.
c) try-finally combination.
d) Exception propagation among many methods.
e) Use of getMessage(), printStackTrace() function of Throwable class.
f) Nested try blocks


8. Write a program to throw a checked exception explicitly using 'throw' keyword
and
a) Handle the exception in same method.
b) use throws clause and handle the exception in some other method
(calling method)
c) Don't either handle or use the throws clause. Observe the result.

9. Repeat program 8 with unchecked Exception and demonstrate the difference in both
program.

10. Create a user defined exception to check whether your employee exist in your
data structure (use any data structure to store the employees -like array,
ArrayList etc) and throw exception if name is not in the employees list. Use the
catch and finally block to make an appropriate solution.

11. Write a program to demonstrate the use of equals method of Object class and
compare its functionality with ( = = ) operator.

12. Modify program 1 with Integer class Object. Use the override equals method of
Integer with two different object wrapping same primitive int value
( like -10). demonstrate the difference in the output from program 11.13. Demonstrate the use of ceil(), floor(), round(), random(), abs(), max(), min()
methods of Math class.

14. Write a program to invoke garbage collector and show the details of free memory
before and after the garbage collection.

15. Write a program to print all System properties using system class.

16. Define a method setMyProperty (String, String) to set your own system property
and use the same system property in another method.
-----------------------------------E N D ---------------------------------
