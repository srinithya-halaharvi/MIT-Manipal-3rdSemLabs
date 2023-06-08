import java.util.Scanner;
class Box{
	double width;
	double height;
	double depth;
	Box(double w,double h,double d){
		width=w;
		height=h;
		depth=d;
	}
	double volume(){
		return width*height*depth ;
	}
}
class MainBox{
	public static void main(String args[]){
		double w,h,d,vol;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter width:");
		w=in.nextDouble();
		System.out.print("Enter height:");
		h=in.nextDouble();
		System.out.print("Enter depth:");
		d=in.nextDouble();
		Box b1=new Box(w,h,d);
		vol=b1.volume();
		System.out.println("Volume="+vol);
	}
}