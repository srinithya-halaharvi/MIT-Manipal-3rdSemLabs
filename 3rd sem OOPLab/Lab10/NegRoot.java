import java.util.Scanner;
class NotNegExcep extends Exception{
    public String toString(){
        return "NotNegativeNumberException";
    }
}
class NegRoot{
    public static void main(String args[])throws NotNegExcep{
        Scanner in=new Scanner(System.in);
        int rootnum,sqrnum;
        System.out.println("Enter negative root of the number:");
        rootnum=in.nextInt();
        System.out.println("Enter the number:");
        sqrnum=in.nextInt();
        try{
            if(rootnum>0){
                throw new NotNegExcep();
            }
            else{
                System.out.println("Negative number entered");
            }
        }
        catch(NotNegExcep e){
            System.out.println(e);
        }
        if(rootnum*rootnum==sqrnum){
            System.out.println(rootnum+" is root of number "+sqrnum);
        }
        else{
            System.out.println(rootnum+" is not root of number "+sqrnum);
        }
    }
    
}
