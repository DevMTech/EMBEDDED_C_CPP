
public class Student_access 
{
	private int rollno;
	
	private static void main(String[] args)
	{
		display();
	}
	
	
	private double CalculateScore()
	{	rollno =1034556;
		return 5.0;		
	}
	
	public void display()
	{
		System.out.println("\n\t rollno = "+rollno);
		
		double d = CalculateScore();
		
		System.out.println("\n\t score = "+d);
	}
	
}
