class Error extends Exception{
    public Error(String str){
        super(str);
    }
    public String toString(){
        return "Error exception displayed";
    }
}
class Userdef{
    public static void main(String args[])throws Error{
        try{
            throw new Error("Hello");
        }
        catch(Error e){
            System.out.println(e);
            //System.out.println(e.getMessage());
        }
    }
}
