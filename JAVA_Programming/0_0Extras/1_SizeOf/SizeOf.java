/**
 * Java Program to print size of primitive data types e.g. byte, int, short, double, float
 * char, short etc, in a method like C programming language's sizeof
 *
 * @author Javin Paul
 */
 
 
 /** There is no sizeof like thing in JAVA **/
 
 
public class SizeOf
{
    public static void main(String args[])
    {
    	int ino = 10010010;
    
        System.out.println(" size of byte in Java is (Input_given)	:"  + sizeof(byte.class));
        System.out.println(" size of short in Java is (in bytes) 	:"  + sizeof(short.class));
        System.out.println(" size of char in Java is (in bytes) 	:"  + sizeof(char.class));
        System.out.println(" size of int in Java is (in bytes) 		:"  + sizeof(int.class));
        System.out.println(" size of long in Java is (in bytes) 	:"  + sizeof(long.class));
        System.out.println(" size of float in Java is (in bytes) 	:"  + sizeof(float.class));
        System.out.println(" size of double in Java is (in bytes) 	:"  + sizeof(double.class));
    }
    
    
    public static int sizeof(Class dataType)
    {
        if (dataType == null) 
        {
            throw new NullPointerException();
        }
        if (dataType == byte.class || dataType == Byte.class)
        {
            return 1;
        }
        if (dataType == short.class || dataType == Short.class)
        {
            return 2;
        }
        if (dataType == char.class || dataType == Character.class)
        {
            return 2;
        }
        if (dataType == int.class || dataType == Integer.class)
        {
            return 4;
        }
        if (dataType == long.class || dataType == Long.class)
        {
            return 8;
        }
        if (dataType == float.class || dataType == Float.class)
        {
            return 4;
        }
        if (dataType == double.class || dataType == Double.class)
        {
            return 8;
        }
        
        return 4; // default for 32-bit memory pointer
    }
    
    public static int sizeOf(Class dataType)
    {
        if (dataType == null)
        {
            throw new NullPointerException();
        }
        if (dataType == byte.class || dataType == Byte.class)
        {
            return Byte.SIZE;
        }
        if (dataType == short.class || dataType == Short.class)
        {
            return Short.SIZE;
        }
        if (dataType == char.class || dataType == Character.class)
        {
            return Character.SIZE;
        }
        if (dataType == int.class || dataType == Integer.class)
        {
            return Integer.SIZE;
        }
        if (dataType == long.class || dataType == Long.class)
        {
            return Long.SIZE;
        }
        if (dataType == float.class || dataType == Float.class)
        {
            return Float.SIZE;
        }
        if (dataType == double.class || dataType == Double.class)
        {
            return Double.SIZE;
        }
        
        return 4; // default for 32-bit memory pointer
    }
}
