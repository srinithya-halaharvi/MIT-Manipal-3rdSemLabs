import java.util.Scanner;
class Armstrong{
	public static void main(String args[]){
		int num,rem,arm=0;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the number:");
		num=in.nextInt();
		int number=num;
		while(num!=0){
			rem=num%10;
			arm=arm+rem*rem*rem;
			num=num/10;
		}
		if(arm==number)
			System.out.println("Armstrong number:");
		else
			System.out.println("Not an Armstrong number");
	}
}