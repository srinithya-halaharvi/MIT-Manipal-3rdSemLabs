class Enter_10{
	public static void main(String args[]){
		int positive=0,negative=0,zero=0,i;
		System.out.println("Enter 10 Numbers:");
		for(i=0;i<10;i++){
			int num=Integer.parseInt(args[i]);
			if(num<0)
				negative++;
			else if(num>0)
				positive++;
			else
				zero++;
		}
		System.out.println("Positive Numbers:"+positive);
		System.out.println("Negative Numbers:"+negative);
		System.out.println("Zeros:"+zero);
	}
}