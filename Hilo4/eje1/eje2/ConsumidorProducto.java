package eje2;

public class ConsumidorProducto extends Thread{
   private Cola cola;
    private long producto = 1;

    public ConsumidorProducto(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {

        for (int i = 1; i <= 10; i++) {

            int numero = cola.leerSinEliminar();
            producto *= numero;

            try {
                Thread.sleep(900);
            } catch (InterruptedException e) { e.printStackTrace(); }
        }

        System.out.println("\n>>> PRODUCTO TOTAL = " + producto);
    }


}
