//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #7
//README
//Due: 3/05/2016
//Handed: 2/25/2016

//can be found @ http://www.katerinachinnppan.com
HOW THE PROGRAM WAS CREATED (OUTLINE)

*Each folder in this zipped file is a package. Package ABSTRACT contains the class
Abstract, package DRIVER contains the class ReadSource, package StudentInfo
contains the classes Statistics, Student and an interface printStudentStat, and a
package UTIL which contains the class Util.

*---CLASS UTIL---*
****PACKAGE UTIL****
Util has a readFile method which reads the text file and populates the Student array.
Util imports the studentInfo package, particuallary the Student class 
(import studentInfo.Student;) Util contains Student.

*---CLASS ABSTRACT---*
****PACKAGE ABSTRACT****
Abstract has a private variable String name. Setters and getters methods, test method
and an abstract method which is implemented in the Student class.

*---INTERFACE printStudentStat---*
****PACKAGE StudentInfo****
Contains public methods findhigh, findlow, fingavg, printhigh, printlow, printavg,
search. These methods are implemented in the Statistics class.

*---CLASS STUDENT---*
****PACKAGE StudentInfo****
Student has three private variables, setters and getters methods. The abstract method
is implemented in Student class.

*---CLASS STATISTICS---*
****PACKAGE StudentInfo****
Statistics has 3 private arrays. Findlow, findhigh, findAVg methods which calculate
the statistics. These methods implement the methods of the same name in the interface
printStudentStat. Methods, printlow, printhigh, printavg, search also implement the 
interface methods.

*---CLASS ReadSource---*
****PACKAGE DRIVER****
ReadSource contains Student, Abstract, Util and Statistics. Calls all the functions
and brings the program to action. THE DRIVER OF THE PROGRAM

