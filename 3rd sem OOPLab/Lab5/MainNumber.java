import java.util.Scanner;
class Number{
    double num;
    Number(double n){
        num=n;
    }
    boolean isZero(){
        if(num==0)
        return true;
        else
        return false;
    }
    boolean isPositive(){
        if(num>0)
        return true;
        else
        return false;
    }
    boolean isNegative(){
        if(num<0)
        return true;
        else
        return false;
    }
    boolean isOdd(){
        if((num%2)!=0)
        return true;
        else 
        return false;
    }
    boolean isEven(){
        if((num%2)==0)
        return true;
        else
        return false;
    }
    boolean isPrime(){
        if(isNegative())
        return false;
        else{
        int i,flag=1;
        for(i=2;i<num/2;i++){
            if(num%i==0){
                flag=0;
                break;
            }
        }
        if(flag==1)
        return true;
        else
        return false;
        }
    }
    boolean isArmstrong(){
        int n=(int)num;
        int rem,sum=0;
        while(n!=0){
            rem=n%10;
            sum=sum+(rem*rem*rem);
            n=n/10;
        }
        if(sum==num)
        return true;
        else
        return false;
    }
}


class MainNumber {
    public static void main(String args[]){
        double number;
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the number:");
        number=in.nextDouble();
        Number n1=new Number(number);
        System.out.println(number+" is Zero:"+n1.isZero());
        System.out.println(number+" is Positive:"+n1.isPositive());
        System.out.println(number+" is Negative:"+n1.isNegative());
        System.out.println(number+" is Odd:"+n1.isOdd());
        System.out.println(number+" is Even:"+n1.isEven());
        System.out.println(number+" is Prime:"+n1.isPrime());
        System.out.println(number+" is Armstrong:"+n1.isArmstrong());
    }
}