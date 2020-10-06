public class Account
{
	int accno;
	int bal;

	int credit_one = 0;
	int debit_one = 0;
	
	static int credit_all = 0;
	static int debit_all = 0;

	public Account(int a, int b)
	{
		this.accno = a;
		this.bal = b;
	}

	void debit(int amt)
	{
		if(bal < amt)
		System.out.println("Insufficient balance");
		else
		{
			this.bal -= amt;
			this.debit_one++;
			debit_all++;
			System.out.println("Available balance after the current debit is " + bal);
		}
	}

	void credit(int amt)
	{
		
		this.bal += amt;
		this.credit_one++;
		credit_all++;
		System.out.println("Available balance after the current credit is " + bal);
		
	}

	void display_credit_trans()
	{
		System.out.println(credit_one + " number of credit transactions done ");
	}
	

	void display_debit_trans()
	{
		System.out.println(debit_one + " number of debit transactions done ");
	}

	void display_bal()
	{
		System.out.println("Your current balance is " + bal + " \n");
	} 

	void display_allcredit()
	{
		System.out.println(credit_all + " number of credit transactions done of all the accounts");
	}
	

	void display_alldebit()
	{
		System.out.println(debit_all + " number of debit transactions done of all the accounts ");
	}
	
}