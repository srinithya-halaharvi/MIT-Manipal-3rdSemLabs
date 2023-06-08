import java.util.Scanner;
class Conversions{
	public static void main(String args[]){
		int i;
		double d;
		char c;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter an integer:");
        i=in.nextInt();
		System.out.println("Enter a double value:");
		d=in.nextDouble();
		System.out.println("Enter a char value:");
		c=in.next().charAt(0);
		System.out.println("Conversions:");
		byte ib=(byte)i;
		int ci=c;
		byte db=(byte)d;
		int di=(int)d;
		System.out.println("Int to Byte:"+ib);
		System.out.println("Char to Int:"+ci);
		System.out.println("Double to Byte:"+db);
		System.out.println("Double to int:"+di);
	}
}