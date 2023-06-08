/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package example2;
class Example2{
    int num;
    static class X{
        static String str="Inside Class X";
        static int num=99;
    }
    public static void main(String args[]){
        X.str="Inside Class Example1";
        Example2.X obj=new Example2.X();
        System.out.println("Value of num="+ obj.num);
    }
}
