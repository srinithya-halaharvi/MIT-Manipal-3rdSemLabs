import java.util.Scanner;
class MatrixPrincipal{
	public static void main(String args[]){
		int m,i,j,sum=0;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter dimension of matrix(m*m):");
		m=in.nextInt();
		int matrix[][]=new int[m][m];
		System.out.print("Enter matrix elements:");
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				matrix[i][j]=in.nextInt();
			}
		}
		for(i=0;i<m;i++){
			for(j=0;j<m;j++)
				System.out.print(matrix[i][j]+" ");
			System.out.println(" ");
		}
		System.out.println("Diagonal elements:");
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(i==j){
					System.out.print(matrix[i][j]+" ");
					sum=sum+matrix[i][j];
				}
			}
		}
		System.out.println(" ");
		System.out.println("Sum of diagonal elements:"+sum);
	}
}