//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #7
//Due: 3/05/2016
//Handed: 2/25/2016

package studentInfo;
public interface printStudentStat {
	
	   public void findLow(Student[] a);
	   public void findHigh(Student[] a);
	   public void findAvg(Student[] a);
	
	   public void printHighScores();
	   public void printLowScores();
	   public void printAvgScores();
	   public void search(Student[] studs);
	   
	   public void debugging(boolean printDebug);

}
