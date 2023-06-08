import java.util.Scanner;
import java.lang.Math;
class Series_2{
    public static void main(String args[]){
        int i,n;
        double sum=0.0,res;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of terms:");
        n=in.nextInt();
        for(i=1;i<=n;i++){
            sum=sum+(Math.pow(1.0/i,i));
            System.out.println("Sum:"+sum);
        }
        System.out.println("Res:"+sum);
    }
}