//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #7
//Due: 3/05/2016
//Handed: 2/25/2016 

package Abstract;
import java.util.Scanner;
public abstract class Abstract {

	//private variables
	private String name;
	
	//sets the name
	public void setName(String name1){
		name = name1;
	}
	
	//returns the name 
	public String getName(){
		return name;
	}
	
	//abstract method, implemented in Student 
	public abstract void enterData();
	
	//makes sure user is in the Abstract class
	public void test(){
		System.out.println("You are in the Abstract Class!");
	}
	
}
