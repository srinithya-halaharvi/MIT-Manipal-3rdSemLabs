class Palindrome{
	public static void main(String args[]){
		int num,n,pal=0,rem;
		num = Integer.parseInt(args[0]);
		n=num;
		while(num>0){
			rem=num%10;
			num=num/10;
			pal=pal*10+rem;
		}
		if(n==pal)
			System.out.println(n+" is Palindrome number");
		else
			System.out.println(n+" is not a Palindrome number");
	}
}
			
			