/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mainbank;
import java.util.Scanner;
/**
 *
 * @author student
 */
class Bank{
    void getRateOfInterest(){
        System.out.println("SBI:8%");
        System.out.println("ICICI:9%");
        System.out.println("AXIS:10%");
    }
}
class SBI extends Bank{
    void getRateOfInterest(){
        System.out.println("SBI:8%");
    }
}
class ICICI extends Bank{
    void getRateOfInterest(){
        System.out.println("ICICI:9%");
    }
}
class AXIS extends Bank{
    void getRateOfInterest(){
        System.out.println("AXIS:10%");
    }
}
public class MainBank {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in=new Scanner(System.in);
        Bank b=new Bank();
        SBI s=new SBI();
        ICICI i=new ICICI();
        AXIS a=new AXIS();
        Bank b1;
        b1=b;
        System.out.println("Enter the name of bank you would like to check the balance of:");
        String name=in.nextLine();
        if(name.equals("SBI")){
            b1=s;
            b1.getRateOfInterest();
        }
        else if(name.equals("ICICI")){
            b1=i;
            b1.getRateOfInterest();
        }
        else if(name.equals("AXIS")){
            b1=a;
            b1.getRateOfInterest();
        }       
    } 
}
