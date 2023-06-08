import java.util.Scanner;
class Series_1{
    public static void main(String args[]){
        int n,i;
        double x,sum,term;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the value of x:");
        x=in.nextDouble();
        System.out.print("Enter the number of iterations:");
        n=in.nextInt();
        x=x/57.2958;
        term=x;
        sum=x;
        for(i=1;i<=n;i++){
            term=(term*(-1*Math.pow(x,2.0)))/(2*i*(2*i+1));
            sum=sum+term;
        }
        System.out.print(sum);    
    }
}