# TDA Cadena de Transmision del Coronavirus

## Descripcion
Simulacion didactica de la cadena de transmision del Coronavirus implementada mediante un TDA. Modela el contagio e interaccion entre personas y objetos a traves de estornudos, contacto fisico, tocar superficies contaminadas y tocarse el rostro, asi como la prevencion mediante lavado de manos y desinfeccion.

## Estructura del proyecto
Arquitectura modular en 3 paquetes/carpetas (implementada en Java y C++):
- `modelo/`  -> Clases del dominio (`Persona`, `Objeto`) que representan las entidades y sus estados de contaminacion e infeccion.
- `negocio/` -> TDA `CadenaTransmision` que administra las colecciones y la logica de propagacion y prevencion del virus.
- `app/`     -> Punto de entrada (`Main.java` / `main.cpp`) con el flujo demostrativo de la simulacion.

## Diagrama de clases
Ver `diagramas/diagrama-clases.md`

## Como ejecutar

### Java
Desde la carpeta `Java`:
```bash
# Compilar todas las clases
javac -d bin src/modelo/*.java src/negocio/*.java src/app/*.java

# Ejecutar
java -cp bin app.Main
```

### C++
> **Nota:** Este proyecto no utiliza archivos de cabecera `.h`. Cada clase contiene su declaracion e implementacion en su archivo `.cpp` con guardas `#ifndef`, incluyendose automaticamente en cadena. Por lo tanto, solo debe compilarse `app/main.cpp`.

Desde la carpeta `CPP`:
```bash
# Compilar
g++ -std=c++17 app/main.cpp -o programa

# Ejecutar (Linux / macOS)
./programa

# Ejecutar (Windows)
programa.exe
```

## Equipo
| Rol | Integrante |
|---|---|
| Lider | Juan Chico |
| Documentacion - Diagramas | Jeremy Torosina |
| Documentacion - Informe | Jullisa Altamirano |
| Backend - Modelo | Joseph Romo |
| Backend - Negocio | Andres Yamuca |
| Frontend - Integracion | Noemi Tuza |

