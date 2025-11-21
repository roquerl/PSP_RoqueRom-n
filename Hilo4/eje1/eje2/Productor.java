package eje2;

public class Productor extends Thread {
    private final Cola cola;

    public Productor(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
       try {
        
        for(int i = 0; i <= 10; i++){

            int num = (int) ((Math.random() * 10 ) + 1);

            cola.producir(num);

            Thread.sleep(300);

        }

       } catch (Exception e) {

        e.printStackTrace();

       }
    }


}
