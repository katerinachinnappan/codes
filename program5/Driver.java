//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #3
//Due: 1/27/2016
//Handed: 1/26/2016

public class Driver {

	public static final int WEEK1 = 5;
	public static void main(String[] args) {
		int i;
		  Franchise franchise1 = FileIO.readData("C:\\Users\\katya\\Documents\\Salesdat.txt");
          for (i = 0; i < WEEK1; i++) {
        	  //GET THE STORE NUMBER 
                  Store store1 = franchise1.getStores(i);
                  System.out.println("\t Store " + i);
                  System.out.println("\n ///////////////////////");
                  //CALL OUTPUT FUNCTION
                  store1.output();
          }

	}

}
