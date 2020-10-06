package com.ems.beans;

public class Employee 
{	
	private int empId; // instance variables
	private String empName;
	private String deptName;
	private double salary;
	
	// Setters(mutators) nad Getters() 
	
	public Employee() // constructor
	{
		
	}
	
	public Employee(int empId, String empName, String deptName, double Salary)
	{	
		this.empId =empId;
		this.empName = empName;
	}
}
