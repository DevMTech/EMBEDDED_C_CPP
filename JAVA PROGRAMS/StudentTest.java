public class StudentTest
{
	public static void main(String args[])
	{

		
		Student s1 = new Student(100,"Snehal");

	//	s1.rollno = 100;
	//	s1.name = "Snehal";	

		Student s2 = new Student(200,"Deb");
	//	s2.name = "Deb";
	//	s2.rollno = 101;	

		Student s3 = new Student(300,"Akhil");

	//	s3.setStudentDetails(102,"Amit");

		Student s4 = new Student(400,"Tina");

	//	s4.get_rollNo();
	//	s4.get_name();		

		Student s5 = new Student(500,"Nikki");		

		System.out.println("\n\t"+s1.rollno);
		System.out.println("\t"+s1.name);

		System.out.println("\n\t"+s2.rollno);
		System.out.println("\t"+s2.name);

		System.out.println("\n\t"+s3.rollno);
		System.out.println("\t"+s3.name);

		s4.displayStudentDetails();

		s5.displayStudentDetails();

	}
}