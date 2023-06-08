import java.util.Scanner;
class Exprsn{
	public static void main(String args[]){
		int a,b;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter two numbers:");
		a=in.nextInt();
		b=in.nextInt();
		int out1=(a << 2) + (b >> 2);
		boolean out2=(b > 0);
		int out3=(a + b * 100) / 10;
	    int out4=a | b;
		System.out.println("i="+out1);
		System.out.println("ii="+out2);
		System.out.println("iii="+out3);
		System.out.println("iv="+out4);
	}
}
