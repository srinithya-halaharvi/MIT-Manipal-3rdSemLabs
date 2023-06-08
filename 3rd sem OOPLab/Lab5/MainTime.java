import java.util.Scanner;
class Time{
	int hours;
	int min;
	int sec;
	Time(){
		hours=0;
		min=0;
		sec=0;
	}
	Time(int h,int m,int s){
		hours=h;
		min=m;
		sec=s;
	}
	void display(){
		System.out.print("Time:");
		System.out.println(hours+":"+min+":"+sec);
	}
	void add(Time a,Time b){
		Time sum=new Time();
		sum.hours=a.hours+b.hours;
		sum.sec=a.sec+b.sec;
		sum.min=a.min+b.min;
		if(sum.sec>60){
			sum.min=sum.min+1;
			sum.sec=sum.sec-60;
		}
		if(sum.min>60){
			sum.hours=sum.hours+1;
			sum.min=sum.min-60;
		}
		sum.display();
	}
	
}
class MainTime{
	public static void main(String args[]){
		int h1,m1,s1,h2,m2,s2;
		Scanner in=new Scanner(System.in);
		System.out.print("Enter time 1 hours,minutes,seconds(with a space seperating them):");
		h1=in.nextInt();
		m1=in.nextInt();
		s1=in.nextInt();
		System.out.print("Enter time 2 hours,minutes,seconds(with a space seperating them):");
		h2=in.nextInt();
		m2=in.nextInt();
		s2=in.nextInt();
		Time t1=new Time(h1,m1,s1);
		Time t2=new Time(h2,m2,s2);
		Time t0=new Time();
		Time sum=new Time();
		t1.display();
		t2.display();
		t0.display();
		System.out.println("Sum of time 1 and time 2:");
		sum.add(t1,t2);
	}
}