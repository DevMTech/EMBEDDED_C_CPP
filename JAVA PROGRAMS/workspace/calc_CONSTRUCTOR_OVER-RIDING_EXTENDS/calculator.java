import java.util.Scanner;
public class calculator extends MyCalc
{
	
	public calculator(int a, int b)
	{			
		super(a, b);
		System.out.println("\n\t in calculator constructor");
		
	}
			

	void mult()
	{
		int mult= this.a * this.b;
		System.out.println("\tIn Calcualtor: Multiplication of 2 nos are \t" + mult);
	}

	void div()
	{
		int div = this.a / this.b;
		System.out.println("\tIn Calcualtor: Division of given two nos are \t" + div);
	}

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter two numbers");
		int a = scan.nextInt();
		int b = scan.nextInt();

		/*System.out.println("Enter 1 for multiplication, 2 for division");
		int n = scan.nextInt();
		calculator calc = new calculator(a,b);
		if(n == 1)
		{	calc.mult();	}
		else
		{	calc.div();	}*/

		calculator calc = new calculator(a,b);
		calc.mult();
		calc.div();

		MyCalc mcalc = new MyCalc(a,b);
		mcalc.mult();
		mcalc.div();

		mcalc = new calculator(a,b);
		mcalc.mult();
		mcalc.div();
				
	}
}