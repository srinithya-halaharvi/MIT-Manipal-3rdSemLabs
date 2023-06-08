import java.util.Scanner;
class Arithematic{
	public static void main(String args[]){
		float num1,num2,ans;
		int operator=0;
		char op,input;
		Scanner in = new Scanner(System.in);
		do{
		System.out.println("Enter first number, operator, second number:");
		num1=in.nextFloat();
		op=in.next().charAt(0);
		num2=in.nextFloat();
		if(op=='*')
			operator=1;
		else if(op=='/')
			operator=2;
		else if(op=='+')
			operator=3;
		else if(op=='-')
			operator=4;
			switch(operator){
				case 1:
				ans=(num1*num2);
				System.out.println("Answer="+ans);
				break;
				case 2:
				ans=(num1/num2);
				System.out.println("Answer="+ans);
				break;
				case 3:
				ans=(num1+num2);
				System.out.println("Answer="+ans);
				break;
				case 4:
				ans=(num1-num2);
				System.out.println("Answer="+ans);
				break;
				default:
				System.out.println("Not valid operator");
			}
			System.out.println("Do another (y/n)?:");
		    input=in.next().charAt(0);
		}while(input=='y');
	}
}