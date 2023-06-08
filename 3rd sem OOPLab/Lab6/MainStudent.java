/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mainstudent;
import java.util.Scanner;
/**
 *
 * @author student
 */
class Student{
    long reg;
    String name;
    int age;
}
class Ug extends Student{
    int sem;
    int fees;
    Ug(long r,String n,int a,int s,int f){
        reg=r;
        name=n;
        age=a;
        sem=s;
        fees=f;
    }
    void display(){
        System.out.println("Details of Student:");
        System.out.println("Under Graduate Student");
        System.out.println("Registraion Number:"+reg);
        System.out.println("Name:              "+name);
        System.out.println("Age:               "+age);
        System.out.println("Semestrer:         "+sem);
        System.out.println("Fees:              "+fees);
    }
}
class Pg extends Student{
    int sem;
    int fees;
    Pg(long r,String n,int a,int s,int f){
        reg=r;
        name=n;
        age=a;
        sem=s;
        fees=f;
    }
    void display(){
        System.out.println("Details of Student:");
        System.out.println("Post Graduate Student");
        System.out.println("Registraion Number:"+reg);
        System.out.println("Name:              "+name);
        System.out.println("Age:               "+age);
        System.out.println("Semestrer:         "+sem);
        System.out.println("Fees:              "+fees);
    }
}
public class MainStudent {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in=new Scanner(System.in);
        long r;
        String n;
        int a,s,f;
        System.out.println("Enter Registration number of student:");
        r=in.nextLong();
        System.out.println("Enter Name of student:");
        n=in.next();
        System.out.println("Enter Age of student:");
        a=in.nextInt();
        System.out.println("Enter Semester:");
        s=in.nextInt();
        System.out.println("Enter Fees:");
        f=in.nextInt();
        System.out.println("Enter UG/PG student:");
        String stud=in.next();
        if(stud.equals("UG")){
            Ug u1=new Ug(r,n,a,s,f);
            u1.display();
        }
        if(stud.equals("PG")){
            Pg p1=new Pg(r,n,a,s,f);
            p1.display();
        }
    }  
}
