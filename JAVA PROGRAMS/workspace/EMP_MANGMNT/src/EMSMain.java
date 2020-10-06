import java.util.Scanner;
public class EMSMain 
{
	public static void main(String[] args)
	{	EMSManager emsMgr = new EMSManager()
		Scanner scan = new Scanner(System.in);
		
		do
		{	System.out.println("\n\n\t\tWelcome to Employee Management System \n\n");
			System.out.println("1. Add new employ");
			System.out.println("2. Search by EmpId");
			System.out.println("3. Display all Emp details");
			System.out.println("4. Sort by Emp Id");
			System.out.println("5. Sort by Emp Name");
			System.out.println("6. Sort by Emp Salary");
			System.out.println("7. Disp Emp Count");
			System.out.println("8. Exit");

			System.out.println("Ënter your choice: ");
			int choice = scan.nextInt(); 
			scan.nextLine();
			
			switch(choice)
			{
				case 1:// add employee
					System.out.println("Enter Emp ID");
					e.setEmpId(scan.nextInt()); scan.nextLine();
					System.out.println("Enter Emp ID");
					e.setEmpName(scan.nextLine());
					System.out.println("Enter Emp ID");
					e.setDeptName(scan.nextLine());
					System.out.println("Enter Emp ID");
					e.setEmpSalary(scan.nextInt());
					
					if()
					
					break;
				case 2:
					System.out.println("enter emp id");
					Emp t = emsMgr.searchByEmpId(scan.nextInt())
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;	
				case 7: //display emp count
					System.out.println("Total emp");
					
				case 8: 
					System.exit(0);
				
			}
		}while(true);
	}
}
