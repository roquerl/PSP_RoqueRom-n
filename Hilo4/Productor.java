import java.util.Random;

public class Productor extends Thread{

    private ColaLimitada cola;
    private Random r = new Random();

    public Productor(ColaLimitada cola){
        this.cola = cola;

    }

    @Override
    public void run() {
        try {
            
            for(int i = 0; i <= 10; i++){

                //Generamos un numero aleatorio
                int numero = r.nextInt(100);

                //Intentamos insertando en la cola 
                cola.producir(numero);;

                //Simulamos tiempo de produción 
                Thread.sleep(100);
            }

        } catch (Exception e) {

            e.printStackTrace();

        }
    }


}