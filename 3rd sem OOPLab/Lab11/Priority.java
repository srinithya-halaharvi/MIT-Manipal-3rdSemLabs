class SetPri extends Thread{
    String name;
    SetPri(String str){
        super(str);
        name=str;
        start();
    }
    public void run(int n){
        try{
            for(int i=0;i<2;i++){
                System.out.println(name+" running...");
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            System.out.println(name+" interrupted");
        }
        System.out.println(name+" terminated");
    }
}
class Priority{
    public static void main(String args[]){
        SetPri t1= new SetPri("Thread1");
        SetPri t2= new SetPri("Thread2");
        SetPri t3= new SetPri("Thread3");
        t1.setPriority(5);
        t2.setPriority(8);
        t3.setPriority(3);
        try{
            t1.join();
            t2.join();
            t3.join();
        }
        catch(InterruptedException e){
            System.out.println("Thread main interrupted");
        }
        System.out.println("Thread main exiting");
    }   
}
