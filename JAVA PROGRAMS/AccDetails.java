import java.util.Scanner;

public class AccDetails {

	public static void main(String[] args) {
		
	
		AccCreDbt acc1 = new AccCreDbt(1,100);
		AccCreDbt acc2 = new AccCreDbt(1,100);
		AccCreDbt acc3 = new AccCreDbt(1,100);

		acc1.depoit(100);
		acc2.depoit(100);
		acc3.depoit(100);
		acc1.depoit(100);
		acc2.depoit(100);
		acc1.depoit(100);
		
		acc1.printDepInCurrentAccount();
		acc2.printDepInCurrentAccount();
		acc3.printDepInCurrentAccount();
		
		AccCreDbt.printDepInAllAccount();
		
		
		acc1.withdraw(100);
		acc2.withdraw(100);
		acc2.withdraw(100);
		acc2.withdraw(100);
		acc1.withdraw(100);
		acc1.withdraw(100);
		acc3.withdraw(100);
		acc1.withdraw(100);
		acc2.withdraw(100);
		acc3.withdraw(100);
		
		acc1.printWdInCurrentAccount();
		acc2.printWdInCurrentAccount();
		acc3.printWdInCurrentAccount();
		
		AccCreDbt.printWdInAllAccount();

	}

}
