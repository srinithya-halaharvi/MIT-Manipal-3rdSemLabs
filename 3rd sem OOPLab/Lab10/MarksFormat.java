import java.util.Scanner;
class MarksFormat{
    public static void main(String args[]){
        int roll,i;
        float per=0;
        int m[]=new int[3];
        String name;
        Scanner in=new Scanner(System.in);
        try{
            System.out.println("Enter Name:");
            name=in.next();
            System.out.println("Enter Roll No.:");
            roll=Integer.parseInt(in.next());
            System.out.println("Enter Marks in three subjects(out of 100):");
            for(i=0;i<3;i++){
                m[i]=Integer.parseInt(in.next());
                per=per+m[i];
            }
        }
        catch(NumberFormatException e){
            System.out.println(e);
        }
        per=per/3;
            System.out.println("Percentage:"+per+"%");
            if(per>90){
                System.out.println("Grade:A+");
            }
            else if(per>80){
                System.out.println("Grade:A");
            }
            else if(per>70){
                System.out.println("Grade:B");
            }
            else if(per>60){
                System.out.println("Grade:C");
            }
            else if(per>50){
                System.out.println("Grade:D");
            }
            else if(per>35){
                System.out.println("Grade:E");
            }
            else{
                System.out.println("Grade:F");
            }
    }
}
