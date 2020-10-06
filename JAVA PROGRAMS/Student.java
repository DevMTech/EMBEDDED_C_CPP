import java.util.Scanner;
public class Student
{

	int rollno;
	String name;
	

	//constructor
	public Student()
	{
	}

	public Student(int rollno, String name)
	{
		this.rollno = rollno;
		this.name = name;	
	}

	public void get_rollNo()
	{
		System.out.print("\n\tENTER ROLL NUMBER :");
		Scanner scn = new Scanner(System.in);
		String rno = scn.next();
		rollno = Integer.parseInt(rno);
	}

	public void get_name()
	{	
		System.out.print("\n\tENTER NAME NUMBER :");
		Scanner scn = new Scanner(System.in);
		name = scn.next();
		
	}

	public void setStudentDetails(int rollno, String name)
	{
		this.rollno = rollno; 	// this.rollno is the instance variable, 
								// roll.no is the argument passed to the function
		this.name = name;
	}

	public void displayStudentDetails()
	{
		System.out.println("\n\t"+rollno);
		System.out.println("\t"+name);
	}	

}

