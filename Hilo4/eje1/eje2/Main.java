package eje2;

public class Main {
    public static void main(String[] args) {
        Cola cola = new Cola();

        Productor p = new Productor(cola);
        ConsumidorSuma c1 = new ConsumidorSuma(cola);
        ConsumidorProducto c2 = new ConsumidorProducto(cola);

        p.start();
        c1.start();
        c2.start();
    }
    
}
