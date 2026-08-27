#ifndef CADENATRANSMISION_CPP
#define CADENATRANSMISION_CPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "../modelo/Persona.cpp"
#include "../modelo/Objeto.cpp"

class CadenaTransmision {
private:
    Persona** personas;
    Objeto** objetos;

    int personasMaximas;
    int objetosMaximos;

    int topePersonas;
    int topeObjetos;

    void validarPersona(Persona* persona) const;
    void validarObjeto(Objeto* objeto) const;
    bool contienePersona(const Persona* persona) const;
    bool contieneObjeto(const Objeto* objeto) const;

public:
    CadenaTransmision(int personasMaximas, int objetosMaximos);
    ~CadenaTransmision();

    void agregarPersona(Persona* persona);
    void agregarObjeto(Objeto* objeto);

    std::string estornudarSobreObjeto(Persona* persona, Objeto* objeto);
    std::string tocarObjeto(Persona* persona, Objeto* objeto);
    std::string tenerContacto(Persona* origen, Persona* destino);
    std::string tocarRostro(Persona* persona);
    std::string lavarManos(Persona* persona);
    std::string desinfectarObjeto(Objeto* objeto);

    void mostrarEstado() const;
};

CadenaTransmision::CadenaTransmision(int personasMaximas, int objetosMaximos) {
    if (personasMaximas <= 0) {
        throw std::invalid_argument("La cantidad maxima de personas debe ser mayor que cero.");
    }
    if (objetosMaximos <= 0) {
        throw std::invalid_argument("La cantidad maxima de objetos debe ser mayor que cero.");
    }

    this->personasMaximas = personasMaximas;
    this->objetosMaximos = objetosMaximos;

    personas = new Persona*[personasMaximas]();
    objetos = new Objeto*[objetosMaximos]();

    topePersonas = 0;
    topeObjetos = 0;
}

CadenaTransmision::~CadenaTransmision() {
    delete[] personas;
    delete[] objetos;
}

void CadenaTransmision::agregarPersona(Persona* persona) {
    if (persona == nullptr) {
        throw std::invalid_argument("La persona no puede ser nula.");
    }
    if (contienePersona(persona)) {
        throw std::runtime_error("La persona ya esta registrada.");
    }
    if (topePersonas >= personasMaximas) {
        throw std::runtime_error("No hay espacio para agregar otra persona.");
    }
    personas[topePersonas] = persona;
    topePersonas++;
}

void CadenaTransmision::agregarObjeto(Objeto* objeto) {
    if (objeto == nullptr) {
        throw std::invalid_argument("El objeto no puede ser nulo.");
    }
    if (contieneObjeto(objeto)) {
        throw std::runtime_error("El objeto ya esta registrado.");
    }
    if (topeObjetos >= objetosMaximos) {
        throw std::runtime_error("No hay espacio para agregar otro objeto.");
    }
    objetos[topeObjetos] = objeto;
    topeObjetos++;
}

std::string CadenaTransmision::estornudarSobreObjeto(Persona* persona, Objeto* objeto) {
    validarPersona(persona);
    validarObjeto(objeto);

    if (!persona->estaInfectada()) {
        return persona->getNombre() + " no esta infectada. " + objeto->getNombre() + " permanece limpio.";
    }

    objeto->contaminar();

    return persona->getNombre() + " estornuda sobre " + objeto->getNombre() + ". El objeto queda contaminado.";
}

std::string CadenaTransmision::tocarObjeto(Persona* persona, Objeto* objeto) {
    validarPersona(persona);
    validarObjeto(objeto);

    bool manosAntes = persona->tieneManosContaminadas();
    bool objetoAntes = objeto->estaContaminado();

    if (!manosAntes && !objetoAntes) {
        return persona->getNombre() + " toca " + objeto->getNombre() + ", pero ambos estan limpios.";
    }

    if (objetoAntes) {
        persona->contaminarManos();
    }

    if (manosAntes) {
        objeto->contaminar();
    }

    if (objetoAntes && !manosAntes) {
        return persona->getNombre() + " toca " + objeto->getNombre() + ". Sus manos quedan contaminadas.";
    }

    if (manosAntes && !objetoAntes) {
        return persona->getNombre() + " toca " + objeto->getNombre() + ". El objeto queda contaminado.";
    }

    return persona->getNombre() + " toca " + objeto->getNombre() + ". Manos y objeto siguen contaminados.";
}

std::string CadenaTransmision::tenerContacto(Persona* origen, Persona* destino) {
    validarPersona(origen);
    validarPersona(destino);

    if (origen == destino) {
        throw std::invalid_argument("Las personas deben ser diferentes.");
    }

    if (!origen->tieneManosContaminadas()) {
        return origen->getNombre() + " tiene contacto con " + destino->getNombre() + ", pero no transmite contaminacion.";
    }

    destino->contaminarManos();

    return origen->getNombre() + " tiene contacto con " + destino->getNombre() + ". Las manos de " + destino->getNombre() + " quedan contaminadas.";
}

std::string CadenaTransmision::tocarRostro(Persona* persona) {
    validarPersona(persona);

    if (!persona->tieneManosContaminadas()) {
        return persona->getNombre() + " toca su rostro, pero sus manos estan limpias.";
    }

    if (persona->estaInfectada()) {
        return persona->getNombre() + " ya estaba infectada.";
    }

    persona->infectar();

    return persona->getNombre() + " toca su rostro con las manos contaminadas y se infecta.";
}

std::string CadenaTransmision::lavarManos(Persona* persona) {
    validarPersona(persona);
    persona->lavarManos();
    return persona->getNombre() + " se lava las manos. La cadena de transmision se interrumpe.";
}

std::string CadenaTransmision::desinfectarObjeto(Objeto* objeto) {
    validarObjeto(objeto);
    objeto->desinfectar();
    return objeto->getNombre() + " fue desinfectado y queda limpio.";
}

void CadenaTransmision::mostrarEstado() const {
    std::cout << std::endl << "--- PERSONAS ---" << std::endl;
    for (int i = 0; i < topePersonas; i++) {
        personas[i]->mostrarEstado();
    }

    std::cout << std::endl << "--- OBJETOS ---" << std::endl;
    for (int i = 0; i < topeObjetos; i++) {
        objetos[i]->mostrarEstado();
    }
}

void CadenaTransmision::validarPersona(Persona* persona) const {
    if (persona == nullptr) {
        throw std::invalid_argument("La persona no puede ser nula.");
    }
    if (!contienePersona(persona)) {
        throw std::invalid_argument("La persona no esta registrada en la cadena de transmision.");
    }
}

void CadenaTransmision::validarObjeto(Objeto* objeto) const {
    if (objeto == nullptr) {
        throw std::invalid_argument("El objeto no puede ser nulo.");
    }
    if (!contieneObjeto(objeto)) {
        throw std::invalid_argument("El objeto no esta registrado en la cadena de transmision.");
    }
}

bool CadenaTransmision::contienePersona(const Persona* persona) const {
    for (int i = 0; i < topePersonas; i++) {
        if (personas[i] == persona) {
            return true;
        }
    }
    return false;
}

bool CadenaTransmision::contieneObjeto(const Objeto* objeto) const {
    for (int i = 0; i < topeObjetos; i++) {
        if (objetos[i] == objeto) {
            return true;
        }
    }
    return false;
}

#endif
