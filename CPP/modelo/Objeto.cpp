#ifndef OBJETO_CPP
#define OBJETO_CPP

#include <string>
#include <iostream>
#include <stdexcept>
#include <cctype>

class Objeto {
private:
    const std::string nombre;
    bool contaminado;

    friend class CadenaTransmision;

    void contaminar();
    void desinfectar();

public:
    Objeto(const std::string& nombre);

    std::string getNombre() const;
    bool estaContaminado() const;

    void mostrarEstado() const;
};

static bool nombreObjetoVacio(const std::string& nombre) {
    for (char c : nombre) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

Objeto::Objeto(const std::string& nombre)
    : nombre(nombre), contaminado(false) {
    if (nombreObjetoVacio(this->nombre)) {
        throw std::invalid_argument("El nombre del objeto no puede estar vacio.");
    }
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
