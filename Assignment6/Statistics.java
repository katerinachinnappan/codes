//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #6
//Due: 2/20/2016
//Handed: 2/19/2016


import java.io.Serializable;


class Statistics  implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	//variables start
	  private final int[] lowscores = new int []{100, 100, 100, 100, 100};
	  private final int[] highscores = new int[5];
	  private final double[] avgscores = new double[5];
	  //variables end
	  
	  //find the lowest score: if score is > -1, compare scores and get the lowest one
	    public void findlow(Student[] a) {
	        for (Student stu : a) {
	            for (int i = 0; i < 5; i++) {
	            	
	            	if(stu.getScores(i) > -1)
	                lowscores[i] = Math.min(lowscores[i], stu.getScores(i));
	              
	            }
	        }
	    }

	  //find the highest score: compare the scores, and get the highest one
	    public void findhigh(Student[] a) {
	        for (Student stu : a) {
	            for (int i = 0; i < 5; i++) {
	                highscores[i] = Math.max(highscores[i], stu.getScores(i));
	            }
	        }
	    }


	    //find the average of the scores and divide by amount of total students
	 
	    public void findavg(Student [] a)
	    {
	      int total = 0;
	      int numberOfStudents = 15;
	      int column = 0;
	        
	      for (column = 0; column < 5; column++)
	      {
	        for (int row = 0; row < numberOfStudents; row++)
	        {
	        	//sum up all the scores
	          total += a[row].getScores(column);
	        } 
	        if (numberOfStudents == 0)
	          avgscores[column] = 0;
	        else 
	        {
	        	 avgscores[column] = (double)total / numberOfStudents;
	        }
	
	        total = 0;
	      }  
	 
	    } 

	    //print low score
	    public void printLow() {
	    	for(int i = 0; i < 5; i ++){
	        	System.out.println("Low Score " + lowscores[i]);
	        }
	    }

	    //print high score
	    public void printHigh() {
	        for(int i = 0; i < 5; i ++){
	        	System.out.println("High Score " + highscores[i]);
	        }
	    }

	    //print average
	    public void printAvg() {
	    	
	    		for(int i = 0; i < 5; i ++){
		    		System.out.println("Average Score " + avgscores[i]);
		        }

	}

	  
}