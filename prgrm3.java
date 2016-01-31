//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #2
//Due: 1/20/2016
//Handed: 1/18/2016

public class Info {

	 String name;
	 String address;
	 int age;
	 String phone;
	
	public Info(){
		name = " ";
		address = " ";
		age = 0;
		phone = " ";
	}
	
	public Info(String name1, String address1, int age1, String phone1){
		setUp(name1, address1, age1, phone1);
	}
	
	public  String getName (){
		return name;
	}
	
	public String getAdress (){
		return address;
	}
	
	public int getAge (){
		return age;
	}
	
	public String getPhone (){
		return phone;
	}
	
	public  void setUp (String name1, String address1, int age1, String phone1){
		name = name1;
		address = address1;
		age = age1;
		phone = phone1;
	}
}

