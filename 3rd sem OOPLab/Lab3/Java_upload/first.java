import java.util.Scanner;
public class first {
     public static void main(String args[]){
        int year;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter year:");
        year=in.nextDouble();
        boolean leap=((year%4==0)&&(year%100!=0))||(year%400==0);
        if(leap)
        System.out.println("Laep year");
        else
        System.out.println("Not leap year");  
    }
}

