//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #1
//Due: 1/13/2016

import java.util.Scanner;

public class Loan {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		
		System.out.print("Loan: ");
		double loan = input.nextDouble();
		
		System.out.print("Number of Years: ");
		double years = input.nextDouble();
		
		System.out.print("Annual Interest Rate: ");
		double x = input.nextDouble();
		
		System.out.println("\n");
		
		double annual_rate = x / 100;
		double months = years * 12;
		double y = (1 + (annual_rate / 12));
		double w = Math.pow(y, months);
		double z = annual_rate / 12;
		double monthly_payment = (z) * (loan) * (w) / (w - 1);
		
		System.out.println("Monthly Payment: " + monthly_payment);
		
		double total_payment = monthly_payment * 12;
		
		System.out.println("Total Payment: " + total_payment + "\n");
		
		double monthly_interest_rate =  annual_rate / 12;
		double interest;
		double principal;
		int i;
		
		System.out.println("Payment#\t"+"Interest\t\t\t"+"Principal\t\t\t"
		+"Balance");
		
		for (i = 1; i <= months; i++){
			
			interest = monthly_interest_rate * loan;
			principal = monthly_payment - interest;
			loan = loan - principal;
			System.out.println(i + "\t\t" + interest + "\t\t" + principal +
					"\t\t" + loan);
		}
}
		
}


