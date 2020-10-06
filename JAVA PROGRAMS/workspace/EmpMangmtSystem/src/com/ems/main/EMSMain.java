package com.ems.main;

import java.util.Scanner;

import com.ems.beans.Employee;


public class EMSMain
{
	public static void main(String[] args)
	{	Employee[] empList = new Employee[100];
	
		int count = 0;

		Scanner scan = new Scanner(System.in);
	
		System.out.println("\n\tWelcome");
		System.out.println("\t1 add emp");
		System.out.println("\t2 disp all emp details");
		System.out.println("\t3 search emp by empId");
		System.out.println("\t4 search emp by empName");
		System.out.println("\t5 exit");
		
		System.out.println("\tenter choice");
		int choice = scan.nextInt();
		
		switch(choice)
		{
		case 1:
			
			Employee e = new Employee(int empId, String Name, String dept, double Sal);
			empList[count++]=e;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			System.out.println("\texiting");
			break;
		default:
			System.out.println("\tinvalid choice, try again");
		
		}
	
	}
}
