package eje2;

public class Main {
    public static void main(String[] args) {
          Cola cola = new Cola();

        Productor productor = new Productor(cola);
        ConsumidorSuma consumidor1 = new ConsumidorSuma(cola);
        ConsumidorProducto consumidor2 = new ConsumidorProducto(cola);

        productor.start();
        consumidor1.start();
        consumidor2.start();

        try {
            productor.join();
            consumidor1.join();
            consumidor2.join();
        } catch (Exception e) {
            e.printStackTrace();
        }

        System.out.println("\n>>> EJERCICIO 2 COMPLETADO <<<");
    }
    
}
