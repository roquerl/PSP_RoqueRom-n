package eje2;

public class ConsumidorSuma extends Thread { 

    private final Cola cola;

    public ConsumidorSuma(Cola cola){
        this.cola = cola;
    }

    @Override
    public void run() {
        int suma = 0;

        try {
            
            for(int i = 0; i < 10; i++){
                int n = cola.consumir();
                suma += n;

                System.out.println("Consumidor Suma recibe: " + n + " suma = " + suma);

                Thread.sleep(500);

            }


        } catch (Exception e) {
            // TODO: handle exception
        }
    }
    
}
