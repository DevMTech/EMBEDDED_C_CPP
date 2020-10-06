
/**
 * @author Administrator
 *
 */
public class ArrayDemo1 
{	
	public static void main(String[] args)
	{
		int x[] = new int[5];
		int y[], z[]=null;
		int [] a,b;
		int []c = new int[5]; 
		a = new int[10];
		y = new int[3];
		z = new int[4];
		int i;
		int d[] = {10,20,30,40,50};
		int e[] = new int[]{3,4,5,6,7};
		//x[]={1,2,3,4,5};
		x[0]=10;
		x[3]=30;
		x[2]=20;
		
		for(i=0; i < x.length; i++)
		{
			System.out.print("\t"+x[i]);
		}
		System.out.println();
		for(i=0; i < e.length; i++)
		{
			System.out.print("\t"+e[i]);
		}
		System.out.println();
		for(int h : d)
		{
			System.out.print("\t"+h);
		}
		
		String names[] = new String[5]; // default value = null as string is a reference type
		names[0] = "Amit";
		names[1] = "Sunil";
		names[2] = "Pulkit";
		
		System.out.println();
		
		for(String n : names)
		{
			System.out.print("\t"+n);
		}
		
		int k[][]=new int[3][4];
		
		k[0][0]=102;
		k[1][2]=156;
		k[2][3]=134;
		
		System.out.println("\n\tlength of k = "+k.length+"\n\n");
		
		int m,n;
		
		for(m=0; m<k.length;m++)
		{
			for(n=0;n<k[m].length; n++)
			{
				System.out.print("\tk["+m+"]["+n+"] = "+k[m][n]);
			}
			
			System.out.println();
		}
		System.out.println("\n\n NON RECTANGULAR ARRAY \n");
		int p[][] =new int[3][];
		// NON RECTANGULAR ARRAY
		p[0] = new int[5];
		p[1] = new int[3];
		p[2] = new int[7]; 
		
		p[0][4]=102;
		p[1][2]=156;
		p[2][5]=134;
		
		for(m=0; m<p.length;m++)
		{
			for(n=0;n<p[m].length; n++)
			{
				System.out.print("\tp["+m+"]["+n+"] = "+p[m][n]);
			}
			System.out.println();
		}
	}
}
