package modelo;

/*
 * =========================================================
 * TDA OBJETO
 * =========================================================
 */
public class Objeto {

    private final String nombre;
    private boolean contaminado;

    public Objeto(String nombre) {

        if (nombre == null || nombre.isBlank()) {
            throw new IllegalArgumentException(
                    "El nombre del objeto no puede estar vacio."
            );
        }

        this.nombre = nombre;
        this.contaminado = false;
    }

    public String getNombre() {
        return nombre;
    }

    public boolean estaContaminado() {
        return contaminado;
    }

    /*
     * Metodos de mutacion del estado.
     * Deben usarse solo desde CadenaTransmision.
     */
    public void contaminar() {
        contaminado = true;
    }

    public void desinfectar() {
        contaminado = false;
    }

    public void mostrarEstado() {

        System.out.println(
                "Objeto: " + nombre
                + " | Contaminado: "
                + (contaminado ? "SI" : "NO")
        );
    }
}
