import java.util.Scanner;
class Result{
	int arr[]=new int[3];
	int arr2d[][]=new int[3][3];
	//Result(){
	//	
	//}
	void marks(){
		int i;
		Scanner in=new Scanner(System.in);
		System.out.print("Enter marks obtained in 3 subjects by student 1:");
		for(i=0;i<3;i++)
			arr2d[0][i]=in.nextInt();
		System.out.print("Enter marks obtained in 3 subjects by student 2:");
		for(i=0;i<3;i++)
			arr2d[1][i]=in.nextInt();
		System.out.print("Enter marks obtained in 3 subjects by student 3:");
		for(i=0;i<3;i++)
			arr2d[2][i]=in.nextInt();
	}
	void tot_marks(){
		int i,j,sum=0;
		for(i=0;i<3;i++){
			sum=0;
			for(j=0;j<3;j++)
				sum=sum+arr2d[i][j];
			arr[i]=sum;
		}
	}
	void highest(){
		int i,j;
		for(i=0;i<3;i++){
			int max=0,index=0;
			for(j=0;j<3;j++){
				if(arr2d[j][i]>max){
					max=arr2d[j][i];
					index=j;
				}
			}
			System.out.println("Highest Marks obtained in subject "+(i+1)+" is: "+max);
			System.out.println("Roll No. of student who secured highest marks in subject "+(i+1)+" is: "+(index+1));
		}
	}
	void tot_highest(){
		int i,index=0,max=0;
		for(i=0;i<3;i++){
			if(arr[i]>max){
				max=arr[i];
				index=i;
			}
		}
		System.out.println("Roll No. of student who obtained highest tottal marks is: "+(index+1)+", with total marks scored= "+max);
	}
}

class MainResult{
	public static void main(String args[]){
		Result r=new Result();
		r.marks();
		r.tot_marks();
		r.highest();
		r.tot_highest();
	}
}