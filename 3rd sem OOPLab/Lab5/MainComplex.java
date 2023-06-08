import java.util.Scanner;
class Complex{
	int real;
	int imag;
	void getdata(){
		Scanner in= new Scanner(System.in);
		System.out.print("Enter real int:");
		real=in.nextInt();
		System.out.print("Enter imaginary int:");
		imag=in.nextInt();
	}
	void display(){
		System.out.println(real+"+"+imag+"i");
	}
	void add(int a,Complex b){
		Complex sum= new Complex();
		sum.real=a+b.real;
		sum.imag=b.imag;
		sum.display();
	}
	void add(Complex a,Complex b){
		Complex sum= new Complex();
		sum.real=a.real+b.real;
		sum.imag=a.imag+b.imag;
		sum.display();
	}
}
class MainComplex{
	public static void main(String args[]){
		Scanner in= new Scanner(System.in);
		Complex c1=new Complex();
		Complex c2=new Complex();
		Complex c3=new Complex();
        Complex c4=new Complex();
		c1.getdata();
		c2.getdata();
		System.out.println("Enter integer to be added to C1:");
		int val=in.nextInt();
        System.out.println("C1:");
        c1.display();
        System.out.println("C2:");
        c2.display();
		System.out.println("Integer added to C1:");
		c3.add(val,c1);
        System.out.println("C1 added to C2:");
        c4.add(c1,c2);
	}
}
