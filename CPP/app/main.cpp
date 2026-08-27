#include <iostream>
#include "../negocio/CadenaTransmision.cpp"

int main() {
    Persona carlos("Carlos", true);
    Persona ana("Ana", false);
    Persona luis("Luis", false);
    Objeto teclado("Teclado del computador");

    CadenaTransmision cadena(10, 10);

    cadena.agregarPersona(&carlos);
    cadena.agregarPersona(&ana);
    cadena.agregarPersona(&luis);

    cadena.agregarObjeto(&teclado);

    std::cout << "===== ESTADO INICIAL =====" << std::endl;
    cadena.mostrarEstado();

    std::cout << std::endl << "===== CADENA DE TRANSMISION =====" << std::endl;

    std::cout << cadena.estornudarSobreObjeto(&carlos, &teclado) << std::endl;
    std::cout << cadena.tocarObjeto(&ana, &teclado) << std::endl;
    std::cout << cadena.tenerContacto(&ana, &luis) << std::endl;
    std::cout << cadena.tocarRostro(&luis) << std::endl;

    std::cout << std::endl << "===== ESTADO TRAS EL CONTAGIO =====" << std::endl;
    cadena.mostrarEstado();

    std::cout << std::endl << "===== PREVENCION =====" << std::endl;

    std::cout << cadena.lavarManos(&ana) << std::endl;
    std::cout << cadena.lavarManos(&luis) << std::endl;
    std::cout << cadena.desinfectarObjeto(&teclado) << std::endl;

    std::cout << std::endl << "===== ESTADO FINAL =====" << std::endl;
    cadena.mostrarEstado();

    return 0;
}
