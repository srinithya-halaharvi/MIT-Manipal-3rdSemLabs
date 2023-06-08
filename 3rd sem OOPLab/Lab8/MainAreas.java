/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mainareas;
abstract class Area{
    abstract void compute();
}
class Rectangle extends Area{
    int l,b;
    Rectangle(int len,int bre){
        l=len;
        b=bre;
    }
    void compute(){
        System.out.println("Area of Rectangle="+(l*b));
    }
}
class Circle extends Area{
    int r;
    Circle(int radius){
        r=radius;
    }
    void compute(){
        System.out.println("Area of Rectangle="+(3.14*r*r));
    }
}
public class MainAreas {
    public static void main(String[] args) {
     
    }   
}
