package app;

import modelo.Persona;
import modelo.Objeto;
import negocio.CadenaTransmision;

/**
 * EJEMPLO DIDACTICO: TDA Cadena de Transmision
 */
public class Main {

    public static void main(String[] args) {

        CadenaTransmision cadena = new CadenaTransmision(10, 10);

        Persona carlos = new Persona("Carlos", true);
        Persona ana = new Persona("Ana", false);
        Persona luis = new Persona("Luis", false);

        Objeto teclado = new Objeto("Teclado del computador");

        cadena.agregarPersona(carlos);
        cadena.agregarPersona(ana);
        cadena.agregarPersona(luis);

        cadena.agregarObjeto(teclado);

        System.out.println("===== ESTADO INICIAL =====");
        cadena.mostrarEstado();

        System.out.println("\n===== CADENA DE TRANSMISION =====");

        System.out.println(
                cadena.estornudarSobreObjeto(carlos, teclado)
        );

        System.out.println(
                cadena.tocarObjeto(ana, teclado)
        );

        System.out.println(
                cadena.tenerContacto(ana, luis)
        );

        System.out.println(
                cadena.tocarRostro(luis)
        );

        System.out.println("\n===== ESTADO FINAL =====");
        cadena.mostrarEstado();
    }
}
