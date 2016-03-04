//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #6
//Due: 2/20/2016
//Handed: 2/19/2016

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Serialization {
    /*
     * This method will serialize the objects and store them in the file that was
     * provided
     * */
    public static boolean serialize(String filename, Object statObj){
        try {
            ObjectOutputStream serializer = new ObjectOutputStream(new FileOutputStream(filename));
            serializer.writeObject(statObj);
            serializer.close();
            if(true){
                System.out.println("SERIALIZATION TAKING PLACE :D");
            }

        } catch (IOException exp) {
            exp.printStackTrace();
            return false;
        }
        return true;
    }
   
}