package final_prog;

class final_class_101 
{	final int x=10;
	//x=10;
	
	public void f1()
	{
		System.out.println("\n\tfinal_class_101.f1()");
		System.out.println("\n\tx = "+x);
	}
	
	
}

public class final_test extends final_class_101
{
	
	
	final public void f1()
	{
		System.out.println("\n\tfinal_test.f1()");
	}
	
	/*static void print()
	{
		for(short i=0; i<=500000; i++)
		{
			System.out.println("\n\ti = "+i);
			//print();
		}
		
		System.out.println("\n\tDONE PRINTING");
	}*/
	
	public static void main(String[] args)
	{
		//final_class obj = new final_test();
		//obj.f1();
		
		//final_class objclass = new final_class();
		//objclass.f1();
		
		final_test objtest = new final_test();
		objtest.f1();
				
		final_class_101 obj101 = new final_test();
		obj101.f1();
					
		final_class_101 objclass101 = new final_class_101();
		objclass101.f1();
		
		//print();
	}
	
	

}
