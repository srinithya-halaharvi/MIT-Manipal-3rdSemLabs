/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package maindetails;
import java.util.Scanner;
class Student_Detail{
    String name;
    int id;
    static String college_name="MIT";
    Student_Detail(String name,int id){
        this.id=id;
        this.name=name;
    }
    void display_details(){
        System.out.println("College name:"+college_name);
        System.out.println("Student name:"+name);
        System.out.println("ID:"+id);
    }
}
public class MainDetails {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter number of students:");
        int num=in.nextInt();
        int i,id;
        String n;
        Student_Detail sd[]=new Student_Detail[num];
        for(i=0;i<num;i++){
            System.out.println("Enter name:");
            n=in.next();
            System.out.println("Enter id:");
            id=in.nextInt();
            sd[i]=new Student_Detail(n,id);
        }
        for(i=0;i<num;i++){
            System.out.println("Dertails of student"+(i+1));
            sd[i].display_details();
        }
    }   
}
