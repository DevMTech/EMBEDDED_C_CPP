import java.util.Scanner;
public class Accountclient
{
	public static void main(String args[])
	{
		
		Account[] client = new Account[3];
		client[0] = new Account(0, 2000);
		client[1] = new Account(1, 10000);
		client[2] = new Account(2, 5000);
		int amt, exit=0;
		
		while(exit==0)
		{
		System.out.println("\n\nEnter your account number");
		Scanner scan = new Scanner(System.in);
		int acc = scan.nextInt();

				

		System.out.println("Welcome to your account");
		client[acc].display_bal();

		System.out.print("Press\n 1. Debit\n 2. Credit\n 3. Number of credit transactions done\n");
		System.out.println(" 4. Number of debit transactions done\n 5. Exit");
		int n = scan.nextInt();
		switch(n)
		{
		 case 1: 
			System.out.println("Enter the amount to be debited");
			amt = scan.nextInt();
			client[acc].debit(amt);
			continue;//break;
		case 2:
			System.out.println("Enter the amount to be credited");
			amt = scan.nextInt();
			client[acc].credit(amt);
			continue;//break;
				
		case 3:
			client[acc].display_credit_trans();
			continue;//break;
		case 4:
			client[acc].display_debit_trans();
			continue;//break;
		case 5:
			exit=n; 
			break;
		default: 
			System.out.println("Invalid key\nPlease try again later");
		
		}// end of switch;
		
		}//end of while;
	}
}