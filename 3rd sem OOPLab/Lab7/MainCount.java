/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package maincount;
import java.util.Scanner;

class Counter{
    static int c=0;
    Counter(){
        c=c+1;
    }
}

public class MainCount {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        Counter c[]=new Counter[20];
        int op,i=0;
        do{
            System.out.println("Enter 1 to create an object 0 to stop:");
            op=in.nextInt();
            if(op==1){
                c[i]=new Counter();
                i++;
            }
        }while(op!=0);
        System.out.println("Number of objects created:"+Counter.c);
    }
}
