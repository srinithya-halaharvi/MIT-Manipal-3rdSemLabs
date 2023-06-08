/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package matrixthread;
import java.util.Scanner;
/**
 *
 * @author student
 */
class Matrix extends Thread{
    int mat[][];
    int n;
    int sum;
    Matrix(int m[][],int n){
        mat=new int[m.length][m[0].length];
        for(int i=0;i<m.length;i++){
            for(int j=0;j<m[0].length;j++){
                mat[i][j]=m[i][j];
            }
        }
        this.n=n;
        start();
    }
    public void run(){
        try{
            for(int i=0;i<mat[0].length;i++){
                sum=sum+mat[n][i];
                Thread.sleep(200);
            }
        }
        catch(InterruptedException e){
            System.out.println("Exception in thread");
        }
    }
}
public class Matrixthread {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in=new Scanner(System.in);
        System.out.println("Enter number of rows and columns:");
        int r=in.nextInt();int c=in.nextInt();
        System.out.println("Enter elements");
        int m[][]=new int[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                m[i][j]=in.nextInt();
            }
        }
        int fsum=0;
        Matrix mx[]=new Matrix[r];
        for(int i=0;i<r;i++){
            mx[i]=new Matrix(m,i);
        }
        try{
            for(int i=0;i<r;i++){
                mx[i].join();
            }
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
        for(int i=0;i<r;i++){
            fsum=fsum+mx[i].sum;
        }
        System.out.println("Sum="+fsum);
    }
    
}
