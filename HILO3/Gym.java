public class Gym extends Thread{
    
    public static void main(String[] args) {
         // Crear una sala de entrenamiento
        SalaEntrenamiento sala = new SalaEntrenamiento();

        // Crear y arrancar 20 hilos (clientes)
        for (int i = 1; i <= 20; i++) {
            Cliente c = new Cliente(sala, "Cliente " + i);
            c.start(); // Inicia el hilo
        }
        
    }


}
