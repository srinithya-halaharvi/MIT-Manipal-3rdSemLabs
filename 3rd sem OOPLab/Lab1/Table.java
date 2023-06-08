class Table{
	public static void main(String args[]){
		int num,i,prod=1;
		num = Integer.parseInt(args[0]);
		for(i=1;i<=10;i++){
			prod=num*i;
			System.out.println(num+"*"+i+"="+prod);
		}
	}
}