package modelo;

/*
 * =========================================================
 * TDA PERSONA
 * =========================================================
 */
public class Persona {

    private final String nombre;
    private boolean infectada;
    private boolean manosContaminadas;

    public Persona(String nombre, boolean infectada) {

        if (nombre == null || nombre.isBlank()) {
            throw new IllegalArgumentException(
                    "El nombre no puede estar vacio."
            );
        }

        this.nombre = nombre;
        this.infectada = infectada;
        this.manosContaminadas = false;
    }

    public String getNombre() {
        return nombre;
    }

    public boolean estaInfectada() {
        return infectada;
    }

    public boolean tieneManosContaminadas() {
        return manosContaminadas;
    }

    /*
     * Metodos internos.
     * CadenaTransmision controla cuando se utilizan.
     */
    public void contaminarManos() {
        manosContaminadas = true;
    }

    public void lavarManos() {
        manosContaminadas = false;
    }

    public void infectar() {
        infectada = false;
    }

    public void mostrarEstado() {

        System.out.println(
                "Persona: " + nombre
                + " | Infectada: "
                + (infectada ? "SI" : "NO")
                + " | Manos contaminadas: "
                + (manosContaminadas ? "SI" : "NO")
        );
    }
}
