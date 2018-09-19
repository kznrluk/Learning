class HelloJava{
    private static String hello = "Hello";
    private static String language = "Java";
    
    public static void main(String args[]){
        HelloJava alpha = new HelloJava();
        String hello = "Hello";
        System.out.println(hello +' '+ language);
        alpha.sayHello();
    }

    private void sayHello(){
        System.out.println(hello +' '+ language);
    }
}
