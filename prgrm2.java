/*Katerina Chinnappan
CIS 35A, Section 61Y
Assignment # 1
Due: 1/13/2016
Date Submitted*/

import java.util.Scanner;

public class SqrtRoot {

	/** main method */
	public static void main(String[] args) {
		long n = 0;
		 
        Scanner input = new Scanner(System.in);
            while(n <= 0){
                System.out.print("Please enter any number: ");
                n   = input.nextLong();
            }
 
            double  answer = sqrt(n); 
 
            System.out.println("The square root of "+n+" is: "+answer);
 
    } // End of main
 
    /** sqrt method */
    public static double sqrt(long n){
 
        double nextGuess;
        double lastGuess;
 
            for(lastGuess=1;Math.pow(lastGuess,2)<=n;lastGuess++){ 
 
            }
                nextGuess=(lastGuess+n/lastGuess)/2;
 
                while(Math.abs(nextGuess-lastGuess)>= 0.0001){
 
                    lastGuess=nextGuess;
                    nextGuess=(lastGuess+n/lastGuess)/2;
 
                } 
 
        return nextGuess;
 
    } // End of sqrt
 
  
} // End of public class.
