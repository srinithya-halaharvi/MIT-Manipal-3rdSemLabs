import java.util.Scanner;
class ArrayOver{
    public static void main(String args[]){
        int arr[]=new int[5];int i;
        Scanner in=new Scanner(System.in);
        System.out.print("Enter numbers:");
        try{
            for(i=0;i<10;i++){
                arr[i]=in.nextInt();
            }
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("ArrayOverflowException");
        }
        finally{
            System.out.println("Done");
        }
    }
}
