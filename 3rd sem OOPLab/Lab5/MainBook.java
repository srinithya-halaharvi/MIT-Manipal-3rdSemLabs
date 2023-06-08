import java.util.Scanner;
class Book{
	String title;
	String author;
	int edition;
	Book(String s1,String s2,int edi){
		title=s1;
		author=s2;
		edition=edi;
	}
}
class MainBook{
	public static void main(String args[]){
		Scanner in=new Scanner(System.in);
		//Book[] arr;
		Book arr[] =new Book[6];
		int i,edi;
		String s1,s2;
		for(i=0;i<6;i++){
			System.out.println("Enter Details:");
			System.out.print("Enter title of the book:");
			s1=in.next();
			System.out.print("Enter name of the author:");
			s2=in.next();
			System.out.print("Enter No. of edition:");
			edi=in.nextInt();
			arr[i]=new Book(s1,s2,edi);
		}
		System.out.println("Books of author Harry:");
		for(i=0;i<6;i++){
            if((arr[i].author).equals("Harry"))
				System.out.println(arr[i].title);
        }
	}
}