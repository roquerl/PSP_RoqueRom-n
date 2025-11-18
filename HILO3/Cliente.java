public class Cliente {
    private SalaEntrenamiento sala; // Sala donde quiere entrar
    private String nombre;          // Nombre del cliente

    public Cliente(SalaEntrenamiento sala, String nombre) {
        this.sala = sala;
        this.nombre = nombre;
    }

    @Override
    public void run() {

        // Intentar entrar a la sala
        sala.entrar(nombre);

        // Simulamos que el cliente entrena dentro durante un tiempo aleatorio
        try {
            Thread.sleep((int) (Math.random() * 3000) + 1000); 
            // Entre 1 y 4 segundos
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // El cliente sale de la sala
        sala.salir(nombre);
    }
}
