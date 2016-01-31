//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #2
//Due: 1/20/2016
//Handed: 1/18/2016

import java.util.*;
public class Coin {

	static String sideUp;// either a head or tail?
	
	Coin(){
		Random ran = new Random();
        int face1 = ran.nextInt(2);
	}
	 public void toss() {
	        Random ran = new Random();
	        int face = ran.nextInt(2);
	        if (face == 0) {
	            sideUp = "heads";
	        } else if(face == 1) {
	            sideUp = "tails";
	        }
	    }

	    public String getSideUp() {
	        System.out.println(sideUp);
	        return sideUp;
	    }
	    
	    public void tossCoin(){
	    	int headCounter = 0;
	        int tailCounter = 0;
	        
	        System.out.println("Tossing coin... \n");
	        for (int i = 1; i <= 20; i++) {
	        	toss();
	            if (getSideUp() == "heads") {
	                headCounter++;
	            } else if(getSideUp() == "tails") {
	                tailCounter++;
	            }
	        }
	     
	        System.out.println("\n");
	        System.out.println("Total heads tossed = " + headCounter  + " "
	        		+ "Total tails tossed = "+tailCounter);
	    }

}
