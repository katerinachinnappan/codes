//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #8
//Due: 3/12/2016
//Handed: 3/05/16

This program is an example of spaghetti code, which should be avoided.

I have designed an OuterClass which contains abstract GeometricObject,
Triangle and TestTriangle classes. The classes have their own methods and Triangle
inherits from GeometricObject. The class calculates the area and perimeter of a given
triangle. TestTriangle has a method called testTriangle() which asks the user
to enter the length of the 3 sides, color and whether the triangle is filled.
The results are then displayed.

The OuterClass contains the main method which calls the testTriangle() method.