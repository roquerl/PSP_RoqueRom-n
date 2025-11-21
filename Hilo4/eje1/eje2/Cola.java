package eje2;

public class Cola {
    private final int [] buffer = new int[5];

    private int count = 0;

    private int añadir = 0;

    private int leer = 0;

    //Método para producir números
    public synchronized void producir(int num) throws InterruptedException{
        
        while (count == buffer.length) { //Mienta contador es 0 y tamaño es 0 del buffer espera
            wait();
        }

        //Añadimos en nuestro buffer los numeros
        buffer[añadir] = num;

        //Contamos y sacamos el resto
        añadir = (añadir + 1 ) % buffer.length;

        //Contamos si se ha producido
        count++;

        System.out.println("Productor produce: " + num);

        notifyAll(); //Avisamos a los consumidores

    } 

    //Método para consumir números
    public synchronized int consumir() throws InterruptedException{
        while (count == 0) {
            wait();
        }

        int num = buffer[0];

        leer = (leer + 1) % buffer.length;

        count--;

        notifyAll();

        return num;


    }



}
