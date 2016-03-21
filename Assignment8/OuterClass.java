//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #8
//Due: 3/12/2016
//Handed: 3/05/16

import java.util.Scanner;
import java.util.Date;

public class OuterClass {
	public static void main(String[] args) {
		OuterClass x = new OuterClass();
		 TestTriangle test = x.new TestTriangle();
		 test.testTriangle();
	 }

	 abstract class GeometricObject{
		 private String  color = "white";
		 private boolean  filled;
		 private Date dateCreated;
		 
		 /** Construct  a default  geometric object  */
		 protected GeometricObject() {
			 dateCreated = new Date();
		 }
		 /** Construct  a geometric object  with color and filled value  */
		 protected GeometricObject(String  color, boolean  filled) {
		 dateCreated = new Date();
		 this.color = color;
		 this.filled = filled;
		 }

		 /** Return color */
		 public String  getColor() {
		 return color;
		 }

		 /** Set a new color */
		 public void setColor(String  color1) {
		 color = color1;
		 }

		 /** Return filled. Since filled is boolean ,
		 * the get method  is named  isFilled */
		 public boolean  isFilled() { 
			 return filled;
		 }

		 /** Set a new filled */
		 public void setFilled(boolean  filled1) {
		 filled = filled1;
		 }

		 /** Get dateCreated */
		 public Date getDateCreated() {
		 return dateCreated;
		 }

		 @Override
		 public String  toString() {
		 return "created on " + dateCreated + "\ncolor: " + color +
		 " and filled: " + filled;
		 }

		 /** Abstract method  getArea */
		 public abstract double  getArea();

		 /** Abstract method  getPerimeter */
		 public abstract double  getPerimeter();
		 
	}
	 public class Triangle extends GeometricObject{
		 
		 //private fields
		 private double side1, side2, side3;
		 public Triangle(){
			 side1 = 0.0;
			 side2 = 0.0;
			 side3 = 0.0;
		 }
		 
		 //constructor with parameters, sets the sides
		 public Triangle(double side1a, double side2a, double side3a){
			 side1 = side1a;
			 side2 = side2a;
			 side3 = side3a;
		 }
		@Override
		//implements the abstarct function in GeomtricObject, calculates the ares of triangle
		public double getArea() {
			double x = (side1 + side2 + side3) / 2;
			
			return Math.sqrt(x * (x - side1) * (x - side2) * (x - side3));
		}

		@Override
		//implements the abstarct function in GeomtricObject, calculates the perimeter
		public double getPerimeter() {
			double perimeter = side1 + side2 + side3;
			
			return perimeter;
		}
		
		//print the triangle object :)
		public String toString(){
			return "Triangle:" + "\n"+ "side1 = " + side1 + "\n" + "side2 = " + side2 + "\n" 
		+ "side3 = "+ side3;
		}

	 }
	 
	 public class TestTriangle{
		 public void testTriangle(){
			 //create Outerclass object
			 OuterClass x =  new OuterClass();
			 
			 //create GeometricObject object (abstract)
			 GeometricObject y = new Triangle();
			 
			 //fields
			 double side1, side2, side3;
			 String fill;
			 boolean filled;
			 String color = "";
			 
			 /***close the scanners****/
			 @SuppressWarnings("resource")
			Scanner input = new Scanner(System.in);
			 @SuppressWarnings("resource")
			Scanner input2 = new Scanner(System.in);
			 @SuppressWarnings("resource")
			 Scanner input3 = new Scanner(System.in);
			 
			//read in the user data
			 System.out.println("Please enter side1: ");
			 side1 = input.nextDouble();
			 
			 System.out.println("Please enter side2: ");
			 side2 = input.nextDouble();
			
			 System.out.println("Please enter side3: ");
			 side3 = input.nextDouble();
			 
			 

			 System.out.println("Please enter the color: ");
			 color = input2.nextLine();
			
			 System.out.println("Please enter filled or not filled(true/false) : ");
			 fill = input3.nextLine();
			
			 //convert string to boolean
			 filled = Boolean.parseBoolean(fill);
			 
			 input3.nextLine();
			 
			 //create triangle object
			 Triangle triangle = x.new Triangle(side1, side2, side3);
			 
			 //set color
			 y.setColor(color);
			 
			 //set filled
			 y.setFilled(filled);
	
			
			 //print the results
			 System.out.println("The area is: " + triangle.getArea());
			 System.out.println("The perimeter is: " + triangle.getPerimeter());
			 System.out.println("The color is: " + y.getColor());
			 if(y.isFilled() == true){
				 System.out.println("Triangle is filled :  Boolean Value - " + y.isFilled());
			 }
			 else if(y.isFilled() == false){
				 System.out.println("Traingle is not filled : Boolean Value - " + y.isFilled());
			 }
			 System.out.println("\n");
			 System.out.println(triangle);
			 
			 }
	 }
	 
 }
 
	 




