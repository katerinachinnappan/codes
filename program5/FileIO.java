//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #3
//Due: 1/27/2016
//Handed: 1/26/2016

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
public class FileIO {
	public static final int LINE = 6;
	public static final int WEEK1 = 5;
	public static final int DAY1 = 7;
	//Franchise readData(String filename)
	 public static Franchise readData(String filename) {
		    Franchise franchise = new Franchise(LINE); //there are 6 lines of data
		    //try block
		    try {
		      File inputFile = new File(filename);
		 
		      BufferedReader input = new BufferedReader
		    		  (new InputStreamReader(new FileInputStream(inputFile)));
		   // read the first line, which is the label line
		      String temp = input.readLine(); 
		 
		      for (int i = 0; i < LINE; i++) {
		        temp = input.readLine();
		        //parsing the sales according to their weeks
		        String[] sales = temp.split("\t"); 
		 
		        Store store1 = new Store();
		        for (int j = 0; j < WEEK1; j++) {
		          for (int k = 0; k < DAY1; k++) {
		            String sale = sales[j * DAY1 + k];
		            //call the setter function, pass the week, day and 
		            //parse the sale according to the week # and day #
		            store1.setsaleforweekdayintersection
		            (j, k, Float.parseFloat(sale));
		          }
		        }
		        franchise.setStores(store1, i);
		      }
		 
		    } 
		    //finally catch exception
		    catch (IOException q) {
		      System.err.println(q);
		      return null;
		    }
		    return franchise;
		  }

}
