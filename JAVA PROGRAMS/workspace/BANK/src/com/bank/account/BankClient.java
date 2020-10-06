package com.bank.account;
import java.util.Scanner;
public class BankClient 
{	
	
	public static void main(String[] args)
	{	Bank b = new Bank();
		//Account accountCreated = null;
		boolean flag;
		Scanner scan = new Scanner(System.in); 
		while(true)
		{	
			System.out.println("\n\n\tEnter A/c Id to creat new A/c");
			int id = scan.nextInt();
			
			//accountCreated = b.creat(id);
			flag = b.creat(id);
			//if(accountCreated != null)
			if(flag)
			{
				System.out.println("\n\t New Account with Id : "+id+" Successfully Created");
				System.out.println("\n\n\tEnter initial balance");
				double iBal = scan.nextInt();
				//accountCreated.deposit(iBal);
				b.depositBank(id, iBal);
				 
			}
			else
			{
				System.out.println("\n\tAccount with Id : "+id+" already present");
			}
		}
	}
}
