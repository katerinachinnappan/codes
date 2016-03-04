//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #7
//Due: 3/05/2016
//Handed: 2/25/2016 
package Util;
import java.io.*;
import java.util.StringTokenizer;

import studentInfo.Student;


public class Util {
    public static Student[] readFile(String filename, Student[] stu) {
        // Reads the file and populates the student array

    	//intializing to -90 because I know for sure that it is too small (out of bound)
        int stuCounter = -90;
        try {
           
        	// Open the file
            FileReader file = new FileReader(filename);

            // loading the file into the buffer
            BufferedReader fileBuff = new BufferedReader(file);

            // reading a line from file in a loop using readLine() method
            boolean EOF = false;
            stuCounter = -1;//set to -1 because of the first header line in the file
            while (!EOF) {
                String line = fileBuff.readLine();
                if (line == null){
                    EOF = true;
                    continue;
                }
                else if(stuCounter >= 0){
                    // Tokenize each line 
                    StringTokenizer st = new StringTokenizer(line);

                    // Create the Student
                    stu[stuCounter] = new Student();

                    //intializing to -1 because the first token of the file isn't a quiz
                    int scoreCounter = -1;
                   
                    while (st.hasMoreTokens()) {
                        String curr = st.nextToken();

                        //converting each token from string to int
                        int result = Integer.parseInt(curr);

                        //result is saved in the correct attribute of the Student
                        if(scoreCounter == -1){
                            //set the SID
                            stu[stuCounter].setSID(result);
                        }
                
                        else{
                            //set the Score
                            stu[stuCounter].setScore(result, scoreCounter);
                        }
                        //update the score
                        scoreCounter++; 
                    }
                }
                //update the student
                stuCounter++;
            }
            //close the file
            fileBuff.close();

        } catch (IOException e) {
        	System.out.println("Error -- " + e.toString());
        }

        return shortenArray(stu, stuCounter);
        
    }

    //since there are only 15 students and not 40, we shorten the array to the number
    //of students being actually used
    public static Student[] shortenArray(Student[] a, int count){
        Student[] curr = new Student[count];
        for(int i = 0; i < count; i++){
            curr[i] = a[i];
        }
        return curr;
    }
}
