public class Consumidor extends Thread{
    private ColaLimitada cola;
    private int sumaTotal = 0;

    public Consumidor (ColaLimitada cola){

        this.cola = cola;

    }


    @Override
    public void run() {

        try {


            //Creamos 10 Consumudores
            for(int i = 0; i <= 10; i++){

            //Cada uno de ellos consuma
            int numero = cola.consumir();

            //Almacenamos lo consumido el total
            sumaTotal += numero;

            System.out.println("Suma acumulada: " + sumaTotal);

            //Lo dormimos para comprobar
            Thread.sleep(700);
            
            }

            System.out.println("Suma final consumida: " + sumaTotal);
            
        } catch (Exception e) {
            e.printStackTrace();
        }
       
    }

    
}