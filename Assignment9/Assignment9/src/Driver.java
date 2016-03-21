//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #9
//Due: 3/19/2016
//Handed: 3/18/2016

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Driver {
	  public static void main(String[] args)
      {
		  //create new frame
		  JFrame frame = new JFrame();
		  
		  //option to proceed
		  Object[] options = {"Yes, please",
	                "No, thanks"};
		  
		  //option to close the window and program completely
		  Object[] option1 = {"Close"};
	        
		  //popup dialog
		     int n = JOptionPane.showOptionDialog(frame,
	        	    "Welcome to Disney Cottages! "
	        	    + " Would you like to proceed?",
	        	    "Book Your Disney Stay Now!",
	        	    JOptionPane.YES_NO_CANCEL_OPTION,
	        	    JOptionPane.QUESTION_MESSAGE,
	        	    null,
	        	    options,
	        	    options[1]);
	        
		     //if user presses yes, proceed to program
	        if(n == JOptionPane.YES_OPTION){
	        	 DisneyCottage size = new DisneyCottage();
	        	 size.setSize(421, 545);
	              size.setVisible(true);
	        	
	        }
	        //if user presses no, close, goodbye window and close the program
	        else if(n == JOptionPane.NO_OPTION){
	        	System.out.println("GoodBye!");
	        	 @SuppressWarnings("unused")
				int x = JOptionPane.showOptionDialog(frame,
	 	        	    "Good Bye!"
	 	        	    + " Have a nice day!",
	 	        	    "Thank You For Visiting Disney Cottages",
	 	        	    JOptionPane.YES_NO_CANCEL_OPTION,
	 	        	    JOptionPane.QUESTION_MESSAGE,
	 	        	    null,
	 	        	    option1,
	 	        	    option1[0]);
	        }
	                  
      }
}
