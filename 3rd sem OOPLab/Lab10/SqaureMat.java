import java.util.Scanner;
class NotSquareExcep extends Exception{
    public String toString(){
        return "NotSquareMatrixException";
    }
}
class SquareMat{
    static void isSquare(int m[][])throws NotSquareExcep{
        if(m.length!=m[0].length){
            throw new NotSquareExcep();
        }
        else{
            System.out.println("Valid Square Matrix");
        }
    }
    public static void main(String args[]){
        Scanner in=new Scanner(System.in);
        System.out.print("Enter number of rows and column:");
        int r=in.nextInt();int c=in.nextInt();
        int mat[][]=new int[r][c];
        try{
            isSquare(mat);
        }
        catch(NotSquareExcep e){
            System.out.println(e);
        }
    } 
    
}
