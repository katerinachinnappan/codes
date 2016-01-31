//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #2
//Due: 1/20/2016
//Handed: 1/18/2016

import java.util.Scanner;
public class TestInfo {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		//object #1
		Info x = new Info();
		//object #2
		Info y = new Info("Kate", "1234 Circle Street", 18, "4081234567");
		//object #3
		Info w = new Info();
		//assign x to w, so w gets the Name 
		w = x;
		String choice;
		
		System.out.print("Example: \n");
		System.out.print("\tName: " + y.name + "\n");
		System.out.print("\tAddress: " + y.address + "\n");
		System.out.print("\tAge: " + y.age + "\n");
		System.out.print("\tPhone: " + y.phone + "\n\n");
				
		System.out.print("Enter your name: ");
		x.name = input.nextLine();
				
		System.out.print("Enter your address: ");
		x.address = input.nextLine();
				
		System.out.print("Enter your age: ");
		x.age = input.nextInt();
				
		System.out.print("Enter your phone number: ");
		x.phone = input.next();
			
		System.out.print("Do you want your information private or public?: ");
		choice = input.next();
				
		x.setUp(x.name, x.address, x.age, x.phone);
				
		System.out.println("\n");
		System.out.println("\t Name: " + x.getName());
		System.out.println("\t Address: " + x.getAdress());
		System.out.println("\t Age: " + x.getAge());
		System.out.println("\t Phone: " + x.getPhone());
		System.out.println("\t Choice: " + choice);
			
			
		System.out.println("\n Goodbye " + w.getName());
			
		
	    input.close();
	}
	
}
