import java.util.Scanner;
class Employee{
	String name;
	String city;
	double sal;
	double da;
	double hr;
	void getdata(){
		Scanner in= new Scanner(System.in);
		System.out.print("Enter name:");
		name=in.nextLine();
		System.out.print("Enter city:");
		city=in.nextLine();
		System.out.print("Enter Salary:");
		sal=in.nextDouble();
		System.out.print("Enter Dearest Allowance:");
		da=in.nextDouble();
		System.out.print("Enter House Rent:");
		hr=in.nextDouble();
	}
	double calculate(){
		return(sal+((sal*da)/100.0)+((sal*hr)/100.0));
	}
	void display(){
		double total=calculate();
		System.out.println("Total Salary="+total);
	}
}
class MainEmployee{
	public static void main(String args[]){
		Employee e1=new Employee();
		e1.getdata();
		e1.display();
	}
}