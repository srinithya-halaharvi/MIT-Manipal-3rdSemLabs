class Synchro{
    int n;
    boolean setval=false;
    synchronized int got(){
        if(!setval){
        try{
            wait();
        }
        catch(InterruptedException e){
            System.out.println("Exception");
        }
        }

        System.out.println("Got"+n);
        setval=false;
        notify();
        return n;
    }
    synchronized void put(int n){
        if(setval){
            try{
                wait();
            }
            catch(InterruptedException e){
                System.out.println("Exception");
            }
        }
        this.n=n;
        System.out.println("Put"+n);
        setval=true;
        notify();
    }
}
class A implements Runnable{
    Synchro s;
    A(Synchro s){
        this.s=s;
        new Thread(this,"Producer").start();
    }
    public void run(){
        int i=0;
        while(true){
            s.put(i++);
        }
    }
}

class B implements Runnable{
    Synchro s;
    B(Synchro s){
        this.s=s;
        new Thread(this,"Customer").start();
    }
    public void run(){
        while(true){
            s.got();
        }
    }
}
class Synchronize{
    public static void main(String args[]){
        Synchro s=new Synchro();
        new A(s);
        new B(s);
        System.out.println("Ctrl-c to stop");
    }
}
