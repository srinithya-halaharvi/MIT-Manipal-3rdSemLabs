import java.util.Scanner;
class Strrep{
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in=new Scanner(System.in);
        String str,word;
        System.out.print("Enter string:");
        str=in.nextLine();
        int strlen=str.length();
        System.out.print("Enter word to replace:");
        word=in.nextLine();
        char carr[]=str.toCharArray();
        int i,j,len,count,k=0;
        len=carr.length;
        char darr[]=new char[len];
        for(i=0;i<len;i++){
            count=0;
            for(j=i+1;j<len;j++){
                if((carr[i]==carr[j])&&carr[i]!=' '){
                    count++;
                    carr[j]='0';
                }
            }
            if(count>0 && carr[i]!='0'){
                darr[k]=carr[i];
                k++;
            }
        }
        int len2=darr.length;
        String rep=new String(str);
        for(i=0;i<k;i++){
            String str2= String.valueOf(darr,i,1);
            System.out.println(str2);
            rep=rep.replaceAll(str2,word);
            System.out.println(rep);
        }
        System.out.println(rep);
    }   
}
