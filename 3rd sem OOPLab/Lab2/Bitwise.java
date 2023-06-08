import java.util.Scanner;
class Bitwise{
	public static void main(String args[]){
		int num,m,d;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the number to multiply and divide by 2:");
        num=in.nextInt();
		m=num<<1;
		d=num>>1;
		System.out.println("Number multiplied by 2 is:"+m);
		System.out.println("Number divided by 2 is:"+d);
	}
}