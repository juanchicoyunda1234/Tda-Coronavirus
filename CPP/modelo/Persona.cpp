#ifndef PERSONA_CPP
#define PERSONA_CPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <cctype>

class Persona {
private:
    const std::string nombre;
    bool infectada;
    bool manosContaminadas;

    friend class CadenaTransmision;

    void contaminarManos();
    void lavarManos();
    void infectar();

public:
    Persona(const std::string& nombre, bool infectada);

    std::string getNombre() const;
    bool estaInfectada() const;
    bool tieneManosContaminadas() const;

    void mostrarEstado() const;
};

static bool nombreVacio(const std::string& nombre) {
    for (char c : nombre) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

Persona::Persona(const std::string& nombre, bool infectada)
    : nombre(nombre), infectada(infectada), manosContaminadas(false) {
    if (nombreVacio(this->nombre)) {
        throw std::invalid_argument("El nombre no puede estar vacio.");
    }
}

std::string Persona::getNombre() const {
    return nombre;
}

bool Persona::estaInfectada() const {
    return infectada;
}

bool Persona::tieneManosContaminadas() const {
    return manosContaminadas;
}

void Persona::contaminarManos() {
    manosContaminadas = true;
}

void Persona::lavarManos() {
    manosContaminadas = false;
}

void Persona::infectar() {
    infectada = true;
}

void Persona::mostrarEstado() const {
    std::cout << "Persona: " << nombre
               << " | Infectada: " << (infectada ? "SI" : "NO")
               << " | Manos contaminadas: " << (manosContaminadas ? "SI" : "NO")
               << std::endl;
}

#endif
