//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #6
//Due: 2/20/2016
//Handed: 2/19/2016

public class ReadSource  {

    public static void main(String[] args) {
        Student lab6[] = new Student[40];
        // Populate the student array by reading from file
        lab6 = Util.readFile("C:\\Users\\katya\\Documents\\lab5.txt", lab6);
        Statistics statlab6 = new Statistics();

        // Calculate the quiz stats
        System.out.print("\n");
        statlab6.findlow(lab6);
        statlab6.findhigh(lab6);
        statlab6.findavg(lab6);
        
        statlab6.printLow();
        System.out.print("\n");
        statlab6.printHigh();
        System.out.print("\n");
        statlab6.printAvg();
        
        System.out.print("\n");

        // create a file for each student and their statistics 
        //with the help of serialization
        for(int i = 0; i < 15; i++){
            lab6[i].setStudentStat(statlab6); 
            Serialization.serialize( new String("Stats")+
                    ((Integer)i).toString()+
                    new String(".txt"), lab6[i]);
            lab6[i].getStudentStats();
        }
    }
}
