import java.util.Scanner;
class Prime_num {
    public static void main(String args[]){
        int i,j,m,n;
        boolean prime;
        Scanner in = new Scanner(System.in);
		System.out.print("Enter the limits(m&n):");
		m=in.nextInt();
        n=in.nextInt();
        System.out.println("Prime numbers between "+m+" and "+n+" are:");
        for(i=m;i<n;i++){
            prime=true;
            for(j=2;j<(i/2);j++){
                if(i%j==0){
                    prime=false;
                }
            }
            if(prime)
            System.out.println(i);
        }
    }
}
