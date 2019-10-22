/*********************************************************************************************************************

	a program to invoke garbage collector and show the details of free memory
	before and after the garbage collection.

	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

import java.util.ArrayList;
import java.util.List;

public class MemTest 
{
    public static void main(String[] args)
    {
     
        List<String> list = new ArrayList<String>();
        
        // Get the Java runtime object
        Runtime runtime = Runtime.getRuntime();
     
     	// get the huge memory
        for (int i = 0; i <= 100000; i++)
        {
            list.add("HELLO");
        }
        
        // Calculate the used memory
        long b_memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("[BEFORE] : Used memory is bytes: " + b_memory);
        
        // Run the garbage collector
        runtime.gc();
        
        // Calculate the used memory
        long a_memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("[AFTER_] : Used memory is bytes: " + a_memory);
        
    }
}
