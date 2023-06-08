import java.util.Scanner;
class leap_year{
	public static void main(String args[]){
		int year;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the year");
        year = in.nextInt();
		if(((year%4)!=0)||((year%400)!=0))
			System.out.println("Not a leap year");
		else if((year%4)==0)
			System.out.println("Leap year");
	}
}
	