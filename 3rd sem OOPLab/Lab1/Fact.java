class Fact{
	public static void main(String args[]){
		int num,i,fact=1;
		num = Integer.parseInt(args[0]);
		for(i=1;i<num;i++){
			fact=fact*i;
		}
		System.out.println("Factorial of "+num+" is:"+fact);
	}
}
			