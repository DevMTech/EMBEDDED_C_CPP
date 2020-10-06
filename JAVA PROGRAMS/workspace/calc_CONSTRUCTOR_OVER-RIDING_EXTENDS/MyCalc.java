public class MyCalc
{
	int a;
		int b;
	
	
		
	public MyCalc(int a, int b)
	{	
		this.a = a;
		this.b = b;
		System.out.println("\n\t in MyCalc constructor");
	}
			

	void mult()
	{
		double mult = (double) (this.a * this.b);
		System.out.println("\t In MyCalc: Multiplication of 2 nos are \t" + mult);
	}

	void div()
	{
		double div = (double) (this.a / this.b);
		System.out.println("\t In MyCalc: Division of given two nos are \t" + div);
	}

}