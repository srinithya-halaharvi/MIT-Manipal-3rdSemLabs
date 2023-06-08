/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package boxing;
public class Boxing {
    public static void main(String[] args) {
        Integer num=new Integer(10);
        Integer a=20;
        a+=5;
        int b=num;
        System.out.println("Boxed value:"+num);
        System.out.println("Autoboxed value:"+a);
        System.out.println("Unboxed value:"+b);
    }
    
}
