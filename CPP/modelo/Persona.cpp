#ifndef PERSONA_CPP
#define PERSONA_CPP

#include <string>
#include <iostream>
#include <stdexcept>

class Persona {
private:
    std::string nombre;
    bool infectada;
    bool manosContaminadas;

public:
    Persona(std::string nombre, bool infectada);

    std::string getNombre() const;
    bool estaInfectada() const;
    bool tieneManosContaminadas() const;

    void contaminarManos();
    void lavarManos();
    void infectar();

    void mostrarEstado() const;
};

Persona::Persona(std::string nombre, bool infectada) {
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacio.");
    }
    this->nombre = nombre;
    this->infectada = infectada;
    this->manosContaminadas = false;
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