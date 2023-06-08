/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication6;
import static java.lang.System.out;
import java.util.Scanner;

/**
 *
 * @author student
 */
class Account{
    String cn;
    long an;
    String type;
    Account(){}
    Account(String s1,long l,String s2){
        cn=s1;
        an=l;
        type=s2;
    }
}
class Current extends Account{
    int bal;
    int dep;
    Current(){
        bal=0;
    }
    void accept(){
        System.out.println("Current Bank Account");
        Scanner in=new Scanner(System.in);
        System.out.print("Enter deposit ammount:");
        dep=in.nextInt();
        System.out.println("Amount deposited:"+dep);
        bal=bal+dep;
    }
    void display(){
        System.out.println("Balance:"+bal);
    }
    void compute(){
        System.out.println("No Interest on Current Bank Account");
    }
    void withdraw(){
        Scanner in=new Scanner(System.in);
        System.out.print("Enter withdrewal ammount:");
        int with=in.nextInt();
        if(with>bal){
            System.out.println("Low balance");
        }
        else{
            bal=bal-with;
            System.out.println("Updated balance after withdrawal:"+bal);
        }
    }
    void check(){
        if(bal<1000){
            System.out.println("Amount is less minimum balance, service tax imposed.");
            bal=bal-100;
            System.out.println("Current balance:"+bal);
            System.out.println("Service tax of Rs.100 will be deducted every quarter.");    
        }
        else{
            System.out.println("Your account has suffiecient ammount.");
        }
    }
}
class Savings extends Account{
    int bal;
    int dep;
    Savings(){
        bal=0;
    }
    void accept(){
        Scanner in=new Scanner(System.in);
        System.out.print("Enter deposit ammount:");
        dep=in.nextInt();
        System.out.println("Amount deposited:"+dep);
        bal=bal+dep;
    }
    void display(){
        System.out.println("Balance:"+bal);
    }
    void compute(){
        int interest;
        interest=bal*(5/100);
        System.out.println("Interest:"+interest);
    }
    void withdraw(){
        Scanner in=new Scanner(System.in);
        System.out.print("Enter withdrewal ammount:");
        int with=in.nextInt();
        if(with>bal){
            System.out.println("Low balance,amount cannot be withdrawn");
        }
        else{
            bal=bal-with;
            System.out.println("Updated balance after withdrawal:"+bal);
        }
    }
}
public class JavaApplication6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int option;
        long acc;
        String name,type;
        Scanner in=new Scanner(System.in);
        System.out.print("Enter Account holder's name:");
        name=in.next();
        System.out.print("Enter Account Number:");
        acc=in.nextLong();
        System.out.println("Enter Account type('c' for current account/'s' for savings account):");
        type=in.next();
        Account a1=new Account(name,acc,type);
        Current c1=new Current();;
        Savings s1=new Savings();;
        System.out.println("______________________________________");
        System.out.println("Enter 1 to deposit");
        System.out.println("Enetr 2 to display balance");
        System.out.println("Enter 3 to compute interest");
        System.out.println("Enter 4 to withdraw ammount");
        System.out.println("Enter 5 to check for minimum balance");
        System.out.println("Enter 0 to exit");
        System.out.println("______________________________________");
        do{
            System.out.println("Enter choice:");
            option=in.nextInt();
            switch(option){
                case 1:
                    if((a1.type).equals("c"))
                        c1.accept();
                    else
                        s1.accept();
                    break;
                case 2:
                    if((a1.type).equals("c"))
                        c1.display();
                    else
                        s1.display();
                    break;
                case 3:
                    if((a1.type).equals("c"))
                        c1.compute();
                    else
                        s1.compute();
                    break;
                case 4:
                    if((a1.type).equals("c"))
                        c1.withdraw();
                    else
                        s1.withdraw();
                    break;
                case 5:
                    if((a1.type).equals("c"))
                        c1.check();
                    else
                        System.out.println("No minimum balance to be maintained for svaings Bank Account");
                    break;
                case 0:
                    System.out.println("Thank you!!");
                    break;               
            }
        }while(option!=0);
    }
}
