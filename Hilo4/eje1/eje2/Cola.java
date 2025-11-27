package eje2;

import java.util.LinkedList;
import java.util.Queue;

public class Cola {
   
    private Queue<Integer> cola = new LinkedList<>();
    private final int CAPACIDAD = 5;

    // PRODUCIR (igual que ejercicio 1)
    public synchronized void producir(int numero) {
        while (cola.size() == CAPACIDAD) {
            try {
                System.out.println("Cola llena → Productor esperando...");
                wait();
            } catch (InterruptedException e) { e.printStackTrace(); }
        }

        cola.add(numero);
        System.out.println("Productor produce: " + numero + " | Cola: " + cola);
        notifyAll();
    }

    /**
     * Nuevo método para el ejercicio 2:
     * leerSinEliminar(): permite que varios consumidores lean el MISMO número.
     */
    public synchronized int leerSinEliminar() {

        // Si cola vacía, consumidor espera
        while (cola.isEmpty()) {
            try {
                System.out.println("Cola vacía → Consumidor esperando...");
                wait();
            } catch (InterruptedException e) { e.printStackTrace(); }
        }

        // Leer primer valor sin eliminarlo
        int numero = cola.peek();
        System.out.println("Consumidor lee (sin eliminar): " + numero);

        notifyAll();
        return numero;
    }


}
