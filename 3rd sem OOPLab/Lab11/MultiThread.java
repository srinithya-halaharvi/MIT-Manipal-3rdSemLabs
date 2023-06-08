class CreateThread implements Runnable{
    Thread t;
    String name;
    CreateThread(String str){
        t=new Thread(this,str);
        name=str;
        System.out.println("Thraed:"+this);
        t.start();
    }
    public void run(){
        try{
            for(int i=0;i<3;i++){
                System.out.println("Hello from thread "+name);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            System.out.println("Thread "+name+" interrupted");
        }
        System.out.println("Thread "+name+" exiting");
    }
}
class MultiThread{
    public static void main(String args[]){
        new CreateThread("First");
        new CreateThread("Second");
        new CreateThread("Third");
        try{
            Thread.sleep(10000);
        }
        catch(InterruptedException e){
            System.out.println("Thread main interrupted");
        }
        System.out.println("Thread main exiting");
    }
}
