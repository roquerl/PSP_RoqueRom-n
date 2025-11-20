public class MainProductorConsumidor {

    public static void main(String[] args) {
        
        ColaLimitada cola = new ColaLimitada();

        Productor p = new Productor(cola);
        Consumidor c = new Consumidor(cola);

        p.start();
        c.start();

    }


}