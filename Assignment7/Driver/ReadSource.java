//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #7
//Due: 3/05/2016
//Handed: 2/25/2016 

package Driver;
import Abstract.Abstract;
import Util.Util;
import studentInfo.*;

public class ReadSource {
	
	
	public static void main(String[] args) {

		Student lab7[] = new Student[40];
		//debugging global flag
		final boolean printDebug = true;
        // Populate the student array by reading from file
        lab7 = Util.readFile("C:\\Users\\katya\\Documents\\lab5.txt", lab7);
     
        //interface obj to calculate and print statistics
        printStudentStat obj = new Statistics();
       
        //create new Abstract class 
        Abstract a = new Student();
        
        //call test method
        a.test();
        
      
       //call enterData method
        a.enterData();
        System.out.print("\n");

        
        // Calculate the statistic methods
        obj.findLow(lab7);
        obj.findHigh(lab7);
        obj.findAvg(lab7);
        
        obj.printLowScores();
        System.out.print("\n");
        obj.printHighScores();
        System.out.print("\n");
        obj.printAvgScores();
        System.out.print("\n");
        
        //calling the search function
        obj.search(lab7);
        
        //calling the debugging function
        obj.debugging(printDebug);
        
        
        }

    }

