import java.util.Scanner;
class MatrixAdd{
	public static void main(String args[]){
		int m,n,i,j;
		Scanner in = new Scanner(System.in);
		System.out.print("Enter dimension of the matrices(m*n):");
		m=in.nextInt();
		n=in.nextInt();
		int mat1[][]=new int[m][n];
		int mat2[][]=new int[m][n];
		int c[][]=new int[m][n];
		System.out.print("Enter matrix 1 elements:");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				mat1[i][j]=in.nextInt();
			}
		}
		System.out.print("Enter matrix 2 elements:");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				mat2[i][j]=in.nextInt();
			}
		}
		System.out.println("Sum of Matrices:");
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				c[i][j]=mat1[i][j]+mat2[i][j];
				System.out.print(c[i][j]+" ");
			}
			System.out.println();
		}
	}	
}