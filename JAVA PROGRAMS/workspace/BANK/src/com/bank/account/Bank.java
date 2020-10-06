package com.bank.account;

public class Bank 
{	
	Account[] acc = new Account[2000];
	private int clientCount = 0;
	int i=0, flag=-1;
	
	public void depositBank(int accId, double amt)
	{
		for(i=0; i < clientCount; i++)
		{
			if((acc[i].getID())==accId){flag=i; break;}
		}
		
		if(flag!=-1)
		{
			acc[flag].deposit(amt);
		}
		
		flag=-1;
	}
	
	public boolean creat(int accId)//return type is reference
	{	
		
		if(clientCount<1)
		{	
			acc[0] = new Account();
			acc[0].setId(accId);
			
			clientCount++;
			System.out.println("\n\n\tclientCount = "+clientCount+"\n\n");
			return true;
		}
		else
		{
			for(i=0; i < clientCount; i++)
			{
				if((acc[i].getID())==accId)
				{
					//flag=clientCount+2; 
					break; // id match found, id already present
				}
			}
				
			System.out.println("\n\n\tflag = "+flag+"\n\n");
		
			//if(flag > clientCount)	// id already present
			if(i<clientCount)			// id already present
			{				
				return false; 	
			}
			else
			{	
				acc[i] = new Account();
				acc[i].setId(accId);
				
				clientCount++;
				System.out.println("\n\n\tclientCount = "+clientCount+"\n\n");
				return true;
			}
		
		}
	}
	
	/*public Account creat(int accId)//return type is reference
	{	
		Account temp = null;
		if(clientCount<1)
		{	
			temp = new Account();
			acc[0] = temp;
			acc[0].setId(accId);
			
			clientCount++;
			System.out.println("\n\n\tclientCount = "+clientCount+"\n\n");
			return temp;
		}
		else
		{
			for(i=0; i<clientCount; i++)
			{
				if((acc[i].getID())==accId){
					return null;
				}
			}
				
			System.out.println("\n\n\tflag = "+flag+"\n\n");
		
			temp = new Account();
			temp.setId(accId);
			acc[clientCount++] = temp;
			return temp;
		
		}
	}*/
	
	/*public setInitialBalance(int id, double initbal)
	{
		acc[0].deposit(initBal);
	}*/
}
