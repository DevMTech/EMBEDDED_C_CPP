package com.bank.account;

public class Account 
{
	private int ID;
	private double balance;
	
	public Account()
	{
		
	}
	
	public void deposit(double amt)
	{
		this.balance+=amt;
 	}
	
	public void withdraw(double amt)
	{	if(this.balance>amt)
		{this.balance-=amt;}
		else
		{System.out.println("\n\tInsufficient balance");}
	}
	
	public void setId(int id)
	{
		this.ID = id;
	}
	
	public int getID()
	{
		return this.ID;
	}
	
	public double getBalance()
	{
		return this.balance;
	}
}
