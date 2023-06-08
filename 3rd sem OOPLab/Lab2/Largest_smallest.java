import java.util.Scanner;
class Largest_smallest{
	public static void main(String args[]){
		int a,b,c;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter three numbers:");
		a=in.nextInt();
		b=in.nextInt();
		c=in.nextInt();
		int largest=(a>b)?((a>c)?a:c):((b>c)?b:c);
		int smallest=(a<b)?((a<c)?a:c):((b<c)?b:c);
		System.out.println("Largest:"+largest);
		System.out.println("Smallest:"+smallest);
	}
}