
public class AccCreDbt{

	int accnum;
	int accbal;
	
	int countDepositForCurrentAccount = 0;
	static int countDepositForAllAccount = 0;
	
	int countWithDrawForCurrentAccount = 0;
	static int countWithDrawForAllAccount = 0;

	public AccCreDbt(int accnum, int accbal) {
		super();
		this.accnum = accnum;
		this.accbal = accbal;
	}

	public void depoit(int anum)
	{
		this.accbal += anum;
		this.countDepositForCurrentAccount++;
		countDepositForAllAccount++;
	}
	
	public void withdraw(int anum)
	{
		this.accbal -= anum;
		this.countWithDrawForCurrentAccount++;
		countWithDrawForAllAccount++;
	}
	
	public void printDepInCurrentAccount() {
		System.out.println(countDepositForCurrentAccount);
	}
	
	public void printWdInCurrentAccount() {
		System.out.println(countWithDrawForCurrentAccount);
	}
	
	public static void printDepInAllAccount() {
		System.out.println(countDepositForAllAccount);
	}
	
	public static void printWdInAllAccount() {
		System.out.println(countWithDrawForAllAccount);
	}
}
