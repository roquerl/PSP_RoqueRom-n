package eje2;

public class ConsumidorSuma extends Thread { 

    private Cola cola;
    private int suma = 0;

    public ConsumidorSuma(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {

        for (int i = 1; i <= 10; i++) {

            int numero = cola.leerSinEliminar(); // leer sin poll()
            suma += numero;

            try {
                Thread.sleep(700);
            } catch (InterruptedException e) { e.printStackTrace(); }
        }

        System.out.println("\n>>> SUMA TOTAL = " + suma);
    }
    
}
