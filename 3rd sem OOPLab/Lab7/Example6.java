/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package example6;
class Example6{
    static int i;
    static String s;
    static void display(){
        Example6 obj1=new Example6();
        System.out.println("i:"+obj1.i);
        System.out.println("s:"+obj1.s);
    }
    public static void funcn(){
        display();
    }
    public static void main(String args[]){
        display();
    }
}