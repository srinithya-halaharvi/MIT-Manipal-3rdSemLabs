import java.util.Scanner;
class Menu{
    public static void pal(String str, String data){
        if(str.equals(data)){
            System.out.println("Palindrome");
        }
        else{
            System.out.println("Not Palindrome");
        }
    }
    public static void alpha(String str){
        int i,j;
        char temp;
        char s[]=str.toCharArray();
        for(i=0;i<s.length;i++) {
            for(j=i+1;j<s.length;j++) {
                if((Character.compare(s[i],s[j])>0)&&(s[i]!=' ')&&(s[j]!=' ')){
                    temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
        for(i=0;i<s.length;i++){
            System.out.print(s[i]);
        }
        System.out.println();
    }
    public static String rev(String str){
        StringBuilder sb=new StringBuilder();
        sb.append(str);
        sb.reverse();
        String data =sb.toString();
        return data;
    }
    public static void concat(String str,String cc){
        str=str+cc;
        System.out.println(str);
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter string:");
        String str=sc.nextLine();
        int ch;
        System.out.println("Enter 1 to check whether palindorme string or not");
        System.out.println("Enter 2 to write string in alphabetical order");
        System.out.println("Enter 3 reverse the string");
        System.out.println("Enter 4 to concatenate the original string and the reversed string");
        System.out.println("Enter 0 to exit");
        do{
            System.out.println("Enter choice:");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                String data=rev(str);
                pal(str,data);
                break;
                case 2:
                alpha(str);
                break;
                case 3:
                String str1=rev(str);
                System.out.println(str1);
                break;
                case 4:
                String cc=rev(str);
                concat(str,cc);
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