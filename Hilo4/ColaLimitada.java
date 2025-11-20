import java.util.LinkedList;

public class ColaLimitada {

    //Estructura de cola donde se almacenan los números
    private LinkedList<Integer> cola = new LinkedList<>();

    //Capacidad máxima de la cola 
    private final int capacidad = 5;


    /*
     * Agregamos un numero a la cola.
     * Si la cola esta llena, el productor espera (wait)
     */
    public synchronized void producir (int numero){

        //Si la cola esta llen, el productor debe esperar
        while (cola.size() == capacidad) {
            try {
                System.out.println("Cola llena --> Productor esperando");
                
                //Libero el Lock y espero a notifyAll()
                wait();
                
            } catch (Exception e) {
                // TODO: handle exception
            }

            //Aqui ya tenemos espacio y agregamos el número
            cola.add(numero);
            System.out.println("Productor produce: " + numero + " | Cola: " + cola);

            //Avisamos a los hilos en espera (Consumidor)
            notifyAll();
            
        }



    }

    public synchronized int consumir () throws InterruptedException{

        //Si la cola no hay nada, el consumidor espera 
        while (cola.isEmpty()) {
            System.out.println("Cola vacía, consumidor esperando...");
            wait(); //Libera el monitor y duerma hasta notify()
        }

        //Quitamos el primer elemento
        int numero = cola.removeFirst();

        System.out.println("Consumidor consumió: " + numero);

        //Notificamos al productor que ya ha consumido
        notify();


        return numero;


    }









}
