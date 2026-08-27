#ifndef OBJETO_CPP
#define OBJETO_CPP

#include <string>
#include <iostream>
#include <stdexcept>

class Objeto {
private:
    std::string nombre;
    bool contaminado;

public:
    Objeto(std::string nombre);

    std::string getNombre() const;
    bool estaContaminado() const;

    void contaminar();
    void desinfectar();

    void mostrarEstado() const;
};

Objeto::Objeto(std::string nombre) {
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre del objeto no puede estar vacio.");
    }
    this->nombre = nombre;
    this->contaminado = false;
}

std::string Objeto::getNombre() const {
    return nombre;
}

bool Objeto::estaContaminado() const {
    return contaminado;
}

void Objeto::contaminar() {
    contaminado = true;
}

void Objeto::desinfectar() {
    contaminado = false;
}

void Objeto::mostrarEstado() const {
    std::cout << "Objeto: " << nombre
               << " | Contaminado: " << (contaminado ? "SI" : "NO")
               << std::endl;
}

#endif
