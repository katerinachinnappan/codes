import java.io.Serializable;

//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #6
//Due: 2/20/2016
//Handed: 2/19/2016

public class Student implements Serializable{
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private int SID;
    public int scores[] = new int[5];
    private Statistics studentStatistics;
    //get the SID
    public int getSID() {
        return SID;
    }

    //set the SID
    public void setSID(int sID1) {
        SID = sID1;
    }

    //return the scores
    public int getScores(int i) {
        return scores[i];
    }

    //set the scores
    public void setScores(int[] scores1) {
        scores = scores1;
    }

    public Statistics getStudentStats() {
        return studentStatistics;
    }

    public void setStudentStat(Statistics studentStatistics1) {
    	studentStatistics = studentStatistics1;
    }

}