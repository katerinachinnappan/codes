//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #7
//Due: 3/05/2016
//Handed: 2/25/2016 
package studentInfo;
import java.util.Scanner;

public class Statistics implements printStudentStat {
	 private int[] lowScores = new int[5];
	    private int[] highScores = new int[5];
	    private float[] avgScores = new float[5];


		  //find the lowest score: compare scores and get the lowest one
	    public void findLow(Student[] a) {
	       
	        for(int i = 0; i< lowScores.length; i++){
	            int current = 900;
	            for(int j = 0; j< a.length; j++){
	                if(a[j].getScore(i) < current){
	                    current = a[j].getScore(i);
	                }
	            }
	            lowScores[i] = current;
	        }
	    }

	  //find the highest score: compare the scores, and get the highest one
	    public void findHigh(Student[] a) {
	       
	    	for(int i = 0; i< highScores.length; i++){
	            int current = -99;
	            for(int j = 0; j< a.length; j++){
	                if(a[j].getScore(i) > current){
	                    current = a[j].getScore(i);
	                }
	            }
	            highScores[i] = current;
	        }
	    }

	    //find the average of the scores and divide by amount of total students
	    public void findAvg(Student[] a) {
	       
	    	for(int i = 0; i< avgScores.length; i++){
	            float total = 0;
	            for(int j = 0; j< a.length; j++){
	                total += a[j].getScore(i);
	            }
	            avgScores[i] = total/a.length;
	        }
	    }

	    //print high score
	    public void printHighScores(){
	    	 for(int i = 0; i < 5; i ++){
		        	System.out.println("High Score " + highScores[i]);
		        }
	    }

	    //print low score
	    public void printLowScores(){
	    	for(int i = 0; i < 5; i ++){
	        	System.out.println("Low Score " + lowScores[i]);
	        }
	    }

	    //print average score
	    public void printAvgScores(){
	    	for(int i = 0; i < 5; i ++){
	    		System.out.println("Average Score " + avgScores[i]);
	        }
	    }
	    
	    //search for given SID and print the scores. 
	    public void search(Student[] studs){
	    	Scanner input = new Scanner(System.in);
	    	int studentID = 0;
	    	
	    	while(studentID != 1){
	    		System.out.println("Type student SID for search (enter 1 to quit):");
	    		studentID = input.nextInt();
	    		
	    		for(int i = 0; i < studs.length; i++){
		    	      if(studs[i].getSID() == studentID){
		    	    	  for(int j =0; j < 5; j++){
		    	    		  System.out.println("Score: " + studs[i].getScore(j));
		    	    		 
		    	    	  }	    	         
		    	      }
		    	   }
	    		if (studentID == 1){
	    	    		System.out.println("Good Bye...");
	    	      }    		
	    	}    	   	
	    }
	    
	    public void debugging(boolean printDebug){
			//debugging flag 
	        if(printDebug)
	            System.out.println("debugging enabled");
	          else
	            System.out.println("debugging disabled");
		}

}
