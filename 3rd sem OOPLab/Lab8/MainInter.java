/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package maininter;
import java.util.Scanner;
interface Company{
    void display();
}
class Hardware implements Company{
    String cat;
    String om;
    static int c=0;
    Hardware(String s1,String s2){
        cat=s1;
        om=s2;
        c=c+1;
    }
    public void display(){
        System.out.println("Hardware:");
        System.out.println("Category:"+cat);
        System.out.println("Original Manufacturer:"+om);
    }
}
class Software implements Company{
    String type;
    String os;
    static int k=0;
    Software(String s1,String s2){
        type=s1;
        os=s2;
        k=k+1;
    }
    public void display(){
        System.out.println("Software:");
        System.out.println("Type of software:"+type);
        System.out.println("Operating System:"+os);
    }
}
public class MainInter {
    public static void main(String[] args) {
        int option,i=0,j=0;
        String s1,s2;
        Scanner in=new Scanner(System.in);
        Company h[]=new Hardware[20];
        Company s[]=new Software[20];
        System.out.println("_________________________________");
        System.out.println("Enter 1 to update hardware class");
        System.out.println("Enter 2 to update software class");
        System.out.println("Enter 0 to stop");
        System.out.println("_________________________________");
        do{
            System.out.print("Enter choice:");
            option=in.nextInt();
            switch(option){
                case 1:
                    System.out.print("Enter category:");
                    s1=in.next();
                    System.out.print("Enter Original Manufacturer:");
                    s2=in.next();
                    h[i]=new Hardware(s1,s2);
                    i++;
                    break;
                case 2:
                    System.out.print("Enter type of software:");
                    s1=in.next();
                    System.out.print("Enter Operating Sysytem:");
                    s2=in.next();
                    s[j]=new Software(s1,s2);
                    j++;
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Inavalid choice");   
            }
        }while(option!=0);
        System.out.println("Hardware Items:");
        for(int m=0;m<i;m++){
            h[m].display();
        }
        System.out.println("Software Items:");
        for(int m=0;m<j;m++){
            s[m].display();
        }
        System.out.println("Toatl sales of Hardware items:"+Hardware.c);
        System.out.println("Total sales of Software items:"+Software.k);
    }   
}