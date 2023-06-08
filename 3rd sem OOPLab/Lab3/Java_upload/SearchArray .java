import java.util.Scanner;
class SearchArray{
    public static void main(String args[]){
        int n,i,j=0,sv;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the number of elements:");
        n=in.nextInt();
        int arr[]= new int[n];
        System.out.print("Enter the elements:");
        for(i=0;i<n;i++){
            arr[i]=in.nextInt();
        }
        System.out.print("Enter the search value:");
        sv=in.nextInt();
        System.out.println("The value is found at locations:");
        for(int a:arr){
            if(a==sv){
                System.out.print("arr["+j+"] ");
            }
            j++;
        }
    }
}
