import java.util.Scanner;
class Symmetric{
	public static void main(String args[]){
		int m,i,j;
		boolean sym=false;
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
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(i!=j){
					if(matrix[i][j]==matrix[j][i])
						sym=true;
				}
			}
		}
		if(sym)
			System.out.println("Symmetric Matrix");
		else
			System.out.println("Not Symmetric Matrix"); 
	}
}