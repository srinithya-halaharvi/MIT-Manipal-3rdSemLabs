/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package example4;
class Example4{
    static int num;
    static String mystr;
    static{
        System.out.println("Static Block 1");
        num=68;
        mystr="Block1";
    }
    static{
        System.out.println("Static Block 2");
        num=98;
        mystr="Block2";
    }
    public static void main(String args[]){
        System.out.println("Value of num="+num);
        System.out.println("Value of mystr="+mystr);
    }
}
