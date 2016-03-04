//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #7
//Due: 3/05/2016
//Handed: 2/25/2016  

package studentInfo;
import java.util.Scanner;

import Abstract.Abstract;

//child class of Abstracts
public class Student extends Abstract{
	//private variables
	 	private int SID;
	    private int scores[] = new int[5];
	    private int age;
	    
	    // Setters and Getters
	    
	    //sets the age 
	    public void setAge(int age1){
			   age = age1;
		   }
	    
	    //returns the age 
	    public int getAge(){
	    	return age;
	    }
	   
	    //returns the SID
	    public int getSID() {
	        return SID;
	    }

	    //sets the SID
	    public void setSID(int sID) {
	        SID = sID;
	    }

	    //returns the Scores
	   public int getScore(int i) {
	        return scores[i];
	    }

	   //sets the scores
	   public void setScore(int score, int index) {
	        this.scores[index] = score;
	    }
	   
	   //asks for user information and displays on the console
	   public void enterData(){
		   Scanner input = new Scanner(System.in);
		   System.out.println("Enter your name:");
		   String name1 = input.nextLine();
		  
		   setName(name1);
		   
		   System.out.println("Enter your age:");
		   int age1 = input.nextInt();
		   
		   setAge(age1);
		   
		   System.out.println("Welcome "+ getName()+ " " + "Age " + getAge());
		   
	   }

}
