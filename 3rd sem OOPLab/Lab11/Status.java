class Check extends Thread{
    Thread t;
    String name;
    Check(String str){
        name=str;
        t=new Thread(this,str);
        start();
    }
    public void run(){
        int i;
        try{
            for(i=0;i<3;i++){
                System.out.println(name+" "+i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e){
            System.out.println(name+" interrupted");
        }
        System.out.println(name+" terminated");
    }
}
class Status{
    public static void main(String srgs[]){
        Check t1= new Check("Thread1");
        Check t2= new Check("Thread2");
        try{
            System.out.println(t1.isAlive());
            System.out.println(t2.isAlive());
            t1.join();
            t2.join();
        }
        catch(InterruptedException e){
            System.out.println("Interrupted");
        }
        System.out.println("Main terminated");
        System.out.println(t1.isAlive());
        System.out.println(t2.isAlive());
    }   
}
