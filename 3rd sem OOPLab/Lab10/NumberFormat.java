import java.util.Scanner;
class NumberFormat{
    public static void main(String args[]){
        int num;
        Scanner in=new Scanner(System.in);
        System.out.print("Enter number:");
        try{
            num=Integer.parseInt(in.next());
            System.out.println("You entered number:"+num);
        }
        catch(NumberFormatException e){
            System.out.println(e);
        }
        finally{
            System.out.println("Done");
        }
    }
}
