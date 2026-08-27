#include <iostream>
#include "../negocio/CadenaTransmision.cpp"

int main() {
    CadenaTransmision cadena(10, 10);

    Persona* carlos = new Persona("Carlos", true);
    Persona* ana = new Persona("Ana", false);
    Persona* luis = new Persona("Luis", false);

    Objeto* teclado = new Objeto("Teclado del computador");

    cadena.agregarPersona(carlos);
    cadena.agregarPersona(ana);
    cadena.agregarPersona(luis);

    cadena.agregarObjeto(teclado);

    std::cout << "===== ESTADO INICIAL =====" << std::endl;
    cadena.mostrarEstado();

    std::cout << std::endl << "===== CADENA DE TRANSMISION =====" << std::endl;

    std::cout << cadena.estornudarSobreObjeto(carlos, teclado) << std::endl;
    std::cout << cadena.tocarObjeto(ana, teclado) << std::endl;
    std::cout << cadena.tenerContacto(ana, luis) << std::endl;
    std::cout << cadena.tocarRostro(luis) << std::endl;

    std::cout << std::endl << "===== ESTADO FINAL =====" << std::endl;
    cadena.mostrarEstado();

    delete carlos;
    delete ana;
    delete luis;
    delete teclado;

    return 0;
}
