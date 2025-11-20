package eje2;

public class ConsumidorProducto extends Thread{
    
    private final Cola cola;

    public ConsumidorProducto (Cola cola){
        this.cola = cola;
    }

    @Override
    public void run() {
        int producto = 1;

        try {

            for(int i = 0; i < 10; i++){
                int n = cola.consumir();
                producto *= n;

                System.out.println("Consumidor Producto recibe " + n + " produce = " + producto);
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


}
