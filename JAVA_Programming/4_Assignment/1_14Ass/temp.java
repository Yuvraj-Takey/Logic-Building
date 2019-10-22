/*********************************************************************************************************************


	@Author 	- Yuvraj Takey
	@Title		- DSSD-JAVA

**********************************************************************************************************************/

import java.util.ArrayList;
import java.util.List;

public class PerformanceTest 
{
    private static final long MEGABYTE = 1024L * 1024L;

    public static long bytesToMegabytes(long bytes) 
    {
        return bytes / MEGABYTE;
    }

    public static void main(String[] args)
    {
     
        List<String> list = new ArrayList<String>();
     
        for (int i = 0; i <= 100000; i++)
        {
            list.add("HELLO");
        }
        
        // Get the Java runtime
        Runtime runtime = Runtime.getRuntime();
        // Run the garbage collector
        runtime.gc();
        // Calculate the used memory
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Used memory is bytes: " + memory);
        System.out.println("Used memory is megabytes: " + bytesToMegabytes(memory));
    }
}
