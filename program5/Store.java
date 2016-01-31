//Katerina Chinnappan
//CIS 35A, Section 61Y
//Assignment #3
//Due: 1/27/2016
//Handed: 1/26/2016

public class Store {
	private float salesbyweek[][];
	public static final int DAY1 = 7;
	public static  final int WEEK1 = 5;
	
	//constructor
	Store() {
		salesbyweek = new float[5][7];	
	}
	
	//getters
	float[] getSalesForEntireWeek(int week) {
        float[] sales = new float[7];

        for (int i = 0; i < DAY1; i++) {
                sales[i] = salesbyweek[week][i];
        }

        return sales;
}

	 float getSaleForWeekDayIntersection(int week, int day) {
         return salesbyweek[week][day];
 }
	 float getTotalSalesForWeek(int week) {
         float total = 0;
         for (int i = 0; i < DAY1; i++) {
                 total += salesbyweek[week][i];
         }
         return total;
 }


	 float getAverageSalesForWeek(int week) {
         return getTotalSalesForWeek(week) / DAY1;
 }

	 float getTotalSalesForAllWeeks() {
         float total = 0;
         for (int i = 0; i < WEEK1; i++) {
                 total += getTotalSalesForWeek(i);
         }
         return total;
 }

	 float getAverageWeeklySales() {
         return getTotalSalesForAllWeeks() / WEEK1;
 }

	 int getWeekWithHighestSaleAmount() {
        
		 int maximumWeek = 0;
         float maximumSale = -1;

         for (int i = 0; i < WEEK1; i++) {
                 float sale = getTotalSalesForWeek(i);
                 //comparing that total sales for week is greater than -1
                 if (sale > maximumSale) {
                         maximumSale = sale;
                         maximumWeek = i;
                 }
         }

         return maximumWeek;
 }

	 int getWeekWithLowestSaleAmount() {
         int minimumWeek = 0;
         
         //A constant holding the largest positive finite value 
         float minumumSale = Float.MAX_VALUE;

         for (int i = 0; i < WEEK1; i++) {
                 float sale = getTotalSalesForWeek(i);
                 if (sale < minumumSale) {
                         minumumSale = sale;
                         minimumWeek = i;
                 }
         }

         return minimumWeek;
 }
	 
	//setter
	public void setsaleforweekdayintersection(int week, int day, float sale){
			salesbyweek[week][day]=sale;
		}
	
	
	//output
     public void output() {
         for (int i = 0; i < WEEK1; i++) {
                 System.out.println("\t Week " + i);
                 System.out.println("\t Total Week Sales: " + 
                 getTotalSalesForWeek(i));
                 System.out.println("\t Total Average Week Sales: "+ 
                 getAverageSalesForWeek(i));
                 System.out.println("\n ~~~~");
         }

         System.out.println("\n");
         System.out.println("Total Sales for All Weeks: " 
         + getTotalSalesForAllWeeks());
         System.out.println("Avergae Weekly Sales: "
         + getAverageWeeklySales());
         System.out.println("Highest Week Sale: "
         + getWeekWithHighestSaleAmount());
         System.out.println("Lowest Week Sale: "
         + getWeekWithLowestSaleAmount());
         System.out.println("\n ~~~~");
 }
}
