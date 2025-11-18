public class SalaEntranamiento {
    // Cantidad actual de personas dentro de la sala
    private int aforoActual = 0;

    // Aforo máximo permitido
    private final int AFORO_MAX = 5;

    // Método sincronizado: solo un hilo puede ejecutarlo a la vez
    public synchronized void entrar(String nombre) {

        System.out.println(nombre + " quiere entrar a la sala...");

        // Si la sala está llena, el cliente debe esperar
        while (aforoActual == AFORO_MAX) {
            try {
                System.out.println(nombre + " esperando porque la sala está llena...");
                wait(); // El hilo se bloquea y espera
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // En este punto, ya hay sitio dentro de la sala
        aforoActual++; // Cliente entra
        System.out.println(nombre + " ha entrado. Aforo actual: " + aforoActual);
    }

    // Método sincronizado para salir de la sala
    public synchronized void salir(String nombre) {

        aforoActual--; // Sale una persona
        System.out.println(nombre + " ha salido. Aforo actual: " + aforoActual);

        // Se notifica a todos los hilos esperando, para que revisen si pueden entrar
        notifyAll();
    }
}
