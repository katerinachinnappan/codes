//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #6
//Due: 2/20/2016
//Handed: 2/19/2016

import java.io.*;
import java.util.*;

public class Util
{
	static Student[] readFile(String filename, Student[] stu) {
		//try block start
        try {
            FileReader file = new FileReader(filename);
            BufferedReader buff = new BufferedReader(file);
           
            //counter
            int count = 0;

            //set to false right away
            boolean eof = false;
          
            for (int i = 0; i < stu.length; i++) {
            	//creating Student
                stu[i] = new Student();
                //initializing the scores temporarily to -1
                int[] temp = new int[]{-1,-1,-1,-1,-1};
                //setting the scores
                stu[i].setScores(temp);
            }
           //while not end of file (not false)
            while (!eof) {
                String line = buff.readLine();
                //if line is empty
                if (line == null)
                    break; //break out of loop
                
                //else print out the file
                else {
                	//prints out the file
                    System.out.println(line);

                    //if count is more than 0, proceed 
                    if (count > 0) {
                        StringTokenizer st = new StringTokenizer(line);
                       
                        //set the SID
                        stu[count - 1].setSID(Integer.parseInt(st.nextToken()));
            
                        int scoreCount = 0; //count the scores
                        while (st.hasMoreTokens()) {
                        	stu[count].scores[scoreCount] = 
                        			Integer.parseInt(st.nextToken());
                            scoreCount++; //update the score count
                        
                        }
                       
                    }
                }
                //update counter
                count++;
            }
            
            buff.close();
        }//try block end
        catch (IOException e) {
            System.out.println("Error -- " + e.toString());
        }
        return stu;
    }
} 