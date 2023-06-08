/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ss;
import java.util.Scanner;
/**
 *
 * @author student
 */
public class Ss {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc= new Scanner(System.in); 
        System.out.print("Enter a string: ");  
        String str= sc.nextLine();   
        System.out.println("You have entered: "+str);   
        int len=str.length();
        int count=0;
        int i;
        for(i=0;i<len;i++){
            if(str.charAt(i)!=' '){
                count++;
            }
        }
        System.out.println("Number of characters: "+count);
        String s[]=str.split("\\s");
        int l2=s.length;
        System.out.println("Number of words: "+l2);
        String sen[]=str.split("[!?.]");
        int l3=sen.length;
        System.out.println("Number of sentences: "+l3);
        int vc=0;
        for(i=0;i<len;i++){
            char ch=str.charAt(i);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                vc++;
            }
        }
        System.out.println("Number of vowels: "+vc);
/*System.out.println("Enter:");
String str2=sc.nextLine();
StringBuilder sb=new StringBuilder();
sb.append(str2);
sb.reverse();
String data =sb.toString();
System.out.println(sb);
if(str2.equals(data)){
    System.out.println("yes");
}
else{
    System.out.println("No");
}*/
/*String temp;
for(i = 0; i<s.length; i++) {
    for (int j = i + 1; j < s.length; j++) {
            if(s[i].compareTo(s[j])>0){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
}
for(i=0; i<s.length; i++) {
    System.out.println(s[i]);
}
StringBuffer ssb=new StringBuffer(str);
for(i=0;i<str.length();i++){
   char t=str.charAt(i);
   if(Character.isLowerCase(t)){
       ssb.setCharAt(i,Character.toUpperCase(t));
   }
   else if(Character.isUpperCase(t)){
       ssb.setCharAt(i,Character.toLowerCase(t));
   }
}
System.out.println(ssb);*/
}
}