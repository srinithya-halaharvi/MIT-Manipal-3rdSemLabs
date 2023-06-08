import java.util.Scanner;
class NewThread extends Thread{
    NewThread(){
        super("Extended Thread");
        System.out.println("Thread:" + this);
        start(); // Start the thread
    }
    public void run(){
        try{
            for(int i=0;i<5;i++){
                System.out.println("Extended Thread:"+i);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            System.out.println("Extended Thread interrupted");
        }
        System.out.println("Extended thread exiting");
    }
}
class NewThread2 implements Runnable{
    Thread t;
    NewThread2(){
        t=new Thread(this);
        System.out.println("Thread:" + this);
        t.start(); // Start the thread
    }
    public void run(){
        try{
            for(int i=0;i<5;i++){
                System.out.println("Implemented Thread:"+i);
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            System.out.println("Implemented Thread interrupted");
        }
        System.out.println("Implemented thread exiting");
    }
}
class FirstThread{
    public static void main(String args[]){
        //new NewThread2();
        Scanner in=new Scanner(System.in);
        System.out.println("Enter 1 to create thread by extending Thread class");
        System.out.println("Enter 2 to create thread by implementing Runnable interface");
        System.out.println("Enter choice:");
        int ch=in.nextInt();
        switch(ch){
            case 1:
            new NewThread();
            break;
            case 2:
            new NewThread2();
            break;
            default:
            System.out.println("Invalid Choice");
            break;
        }
        try{
            for(int i=5;i>0;i--){  
                System.out.println("Main Thread: "+i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e){
            System.out.println("Main Thread interrupted");
        }
        System.out.println("Main thread exiting.");
    }
}
