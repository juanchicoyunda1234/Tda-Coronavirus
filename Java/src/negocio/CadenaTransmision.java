package negocio;

import modelo.Persona;
import modelo.Objeto;

/*
 * =========================================================
 * TDA CADENA DE TRANSMISION
 * =========================================================
 */
public class CadenaTransmision {

    private Persona[] personas;
    private Objeto[] objetos;

    private int topePersonas;
    private int topeObjetos;


    /*
     * Constructor
     *
     * personasMaximas = capacidad del vector de personas.
     * objetosMaximos = capacidad del vector de objetos.
     */
    public CadenaTransmision(
            int personasMaximas,
            int objetosMaximos) {

        if (personasMaximas <= 0) {
            throw new IllegalArgumentException(
                    "La cantidad maxima de personas debe ser mayor que cero."
            );
        }

        if (objetosMaximos <= 0) {
            throw new IllegalArgumentException(
                    "La cantidad maxima de objetos debe ser mayor que cero."
            );
        }

        personas = new Persona[personasMaximas];
        objetos = new Objeto[objetosMaximos];

        topePersonas = 0;
        topeObjetos = 0;
    }


    /*
     * =====================================================
     * AGREGAR PERSONA
     * =====================================================
     */
    public void agregarPersona(Persona persona) {

        if (persona == null) {
            throw new IllegalArgumentException(
                    "La persona no puede ser nula."
            );
        }

        if (topePersonas >= personas.length) {
            throw new IllegalStateException(
                    "No hay espacio para agregar otra persona."
            );
        }

        personas[topePersonas] = persona;
        topePersonas++;
    }


    /*
     * =====================================================
     * AGREGAR OBJETO
     * =====================================================
     */
    public void agregarObjeto(Objeto objeto) {

        if (objeto == null) {
            throw new IllegalArgumentException(
                    "El objeto no puede ser nulo."
            );
        }

        if (topeObjetos >= objetos.length) {
            throw new IllegalStateException(
                    "No hay espacio para agregar otro objeto."
            );
        }

        objetos[topeObjetos] = objeto;
        topeObjetos++;
    }


    /*
     * =====================================================
     * ESTORNUDAR SOBRE OBJETO
     * =====================================================
     */
    public String estornudarSobreObjeto(
            Persona persona,
            Objeto objeto) {

        validarPersona(persona);
        validarObjeto(objeto);

        if (!persona.estaInfectada()) {

            return persona.getNombre()
                    + " no esta infectada. "
                    + objeto.getNombre()
                    + " permanece limpio.";
        }

        objeto.contaminar();

        return persona.getNombre()
                + " estornuda sobre "
                + objeto.getNombre()
                + ". El objeto queda contaminado.";
    }


    /*
     * =====================================================
     * TOCAR OBJETO
     * =====================================================
     */
    public String tocarObjeto(
            Persona persona,
            Objeto objeto) {

        validarPersona(persona);
        validarObjeto(objeto);

        if (!objeto.estaContaminado()) {

            return persona.getNombre()
                    + " toca "
                    + objeto.getNombre()
                    + ", pero el objeto esta limpio.";
        }

        persona.contaminarManos();

        return persona.getNombre()
                + " toca "
                + objeto.getNombre()
                + ". Sus manos quedan contaminadas.";
    }


    /*
     * =====================================================
     * TENER CONTACTO
     * =====================================================
     */
    public String tenerContacto(
            Persona origen,
            Persona destino) {

        validarPersona(origen);
        validarPersona(destino);

        if (origen == destino) {
            throw new IllegalArgumentException(
                    "Las personas deben ser diferentes."
            );
        }

        if (!origen.tieneManosContaminadas()) {

            return origen.getNombre()
                    + " tiene contacto con "
                    + destino.getNombre()
                    + ", pero no transmite contaminacion.";
        }

        destino.contaminarManos();

        return origen.getNombre()
                + " tiene contacto con "
                + destino.getNombre()
                + ". Las manos de "
                + destino.getNombre()
                + " quedan contaminadas.";
    }


    /*
     * =====================================================
     * TOCAR ROSTRO
     * =====================================================
     */
    public String tocarRostro(Persona persona) {

        validarPersona(persona);

        if (!persona.tieneManosContaminadas()) {

            return persona.getNombre()
                    + " toca su rostro, pero sus manos estan limpias.";
        }

        if (persona.estaInfectada()) {

            return persona.getNombre()
                    + " ya estaba infectada.";
        }

        persona.infectar();

        return persona.getNombre()
                + " toca su rostro con las manos contaminadas "
                + "y se infecta.";
    }


    /*
     * =====================================================
     * LAVAR MANOS
     * =====================================================
     */
    public String lavarManos(Persona persona) {

        validarPersona(persona);

        persona.lavarManos();

        return persona.getNombre()
                + " se lava las manos. "
                + "La cadena de transmision se interrumpe.";
    }


    /*
     * =====================================================
     * DESINFECTAR OBJETO
     * =====================================================
     */
    public String desinfectarObjeto(Objeto objeto) {

        validarObjeto(objeto);

        objeto.desinfectar();

        return objeto.getNombre()
                + " fue desinfectado y queda limpio.";
    }


    /*
     * =====================================================
     * MOSTRAR ESTADO
     * =====================================================
     */
    public void mostrarEstado() {

        System.out.println("\n--- PERSONAS ---");

        for (int i = 0; i < topePersonas; i++) {
            personas[i].mostrarEstado();
        }

        System.out.println("\n--- OBJETOS ---");

        for (int i = 0; i < topeObjetos; i++) {
            objetos[i].mostrarEstado();
        }
    }


    /*
     * =====================================================
     * VALIDACIONES
     * =====================================================
     */
    private void validarPersona(Persona persona) {

        if (persona == null) {
            throw new IllegalArgumentException(
                    "La persona no puede ser nula."
            );
        }
    }

    private void validarObjeto(Objeto objeto) {

        if (objeto == null) {
            throw new IllegalArgumentException(
                    "El objeto no puede ser nulo."
            );
        }
    }
}
