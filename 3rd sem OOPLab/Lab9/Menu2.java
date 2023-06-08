import java.util.Scanner;
class Menu2{
    public static void comp(String s1){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter string2:");
        String s2=sc.nextLine();
        if(s1.compareTo(s2)>0){
            System.out.println(s1+" is greater than "+s2);
        }
        else if(s1.compareTo(s2)<0){
            System.out.println(s1+" is lesser than "+s2);
        }
        else if(s1.compareTo(s2)==0){
            System.out.println(s1+" is equal to "+s2);
        }
    }
    public static void convert(String str){
        StringBuffer ssb=new StringBuffer(str);int i;
        for(i=0;i<str.length();i++){
            char temp=str.charAt(i);
            if(Character.isLowerCase(temp)){
                ssb.setCharAt(i,Character.toUpperCase(temp));
            }
            else if(Character.isUpperCase(temp)){
                ssb.setCharAt(i,Character.toLowerCase(temp));
            }
        }
        System.out.println(ssb); 
    }
    public static boolean substr(String str){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter sub string:");
        String ss=sc.nextLine();
        if(str.contains(ss)){
            System.out.println(ss+" is substring of "+str);
            return true;
        }
        else{
            System.out.println(ss+" is not a substring of "+str);
            return false;
        }
    }
    public static void replace(String str){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter sub string:");
        String sub=sc.nextLine();
        //boolean b=substr(str);
        if(str.contains(sub)){
            System.out.println(sub+" is substring of "+str);
            str=str.replaceAll(sub,"Hello");
            System.out.println(str);
        }
        else{
            System.out.println(sub+" is not a substring of "+str);
            //return false;
        }
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter String:");
        String str=sc.nextLine();
        int ch;
        System.out.println("Enter 1 to compare two strings.");
        System.out.println("Enter 2 to convert uppercase character to lower and vice-versa");
        System.out.println("Enter 3 to display whether an entered string is a substring of the other or not");
        System.out.println("Enter 4 to replace");
        System.out.println("Enter 0 to exit");
        do{
            System.out.println("Enter choice:");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                comp(str);
                break;
                case 2:
                convert(str);
                break;
                case 3:
                substr(str);
                break;
                case 4:
                replace(str);
                break;
                case 0:
                System.out.println("Thank you");
                break;
                default:
                System.out.println("Invalid choice");
                break;
            }
        }while(ch!=0);
    }
}