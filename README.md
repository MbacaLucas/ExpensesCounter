# 📊 Sistema de Control de Gastos Personales

![C++](https://img.shields.io/badge/C++-17-blue.svg?style=flat-square&logo=c%2B%2B)
![Estado](https://img.shields.io/badge/Estado-Versión%201.1-green.svg?style=flat-square)
![Licencia](https://img.shields.io/badge/Licencia-MIT-yellow.svg?style=flat-square)

Una aplicación de **Interfaz de Línea de Comandos (CLI)** desarrollada en C++ para gestionar y rastrear gastos mensuales con un enfoque en la integridad de datos y arquitectura limpia.



## 🎯 Descripción del Proyecto
Este sistema permite registrar gastos, categorizarlos mediante un catálogo predefinido y generar un reporte financiero formateado. Se destaca por el uso de características de **C++ Moderno** como Lambdas, Iteradores y Algoritmos Estándar.

## 🚀 Características Técnicas
* **Estructuras de Datos**: Implementación de `struct` para el modelado de entidades (`Category` y `Expense`).
* **Validación de Entradas**: Bucles `do-while` robustos para asegurar que solo se procesen IDs de categoría válidos.
* **Algoritmos Modernos**:
    * `std::find_if`: Utilizado para vincular IDs de gastos con nombres de categorías de forma eficiente.
    * `std::accumulate`: Realiza la suma de alto rendimiento de todos los montos registrados.
* **Manipulación de I/O**: Salida tabular profesional usando `<iomanip>` con precisión decimal fija.

## 🛠️ Requisitos y Compilación
Para compilar este proyecto, se necesita un compilador que soporte el estándar **C++17** o superior (GCC, Clang o MSVC).

```bash
# Compilar el proyecto
g++ -std=c++17 -o control_gastos main.cpp

# Ejecutar la aplicación
./control_gastos

------------------------------------------------------------
ID   Category       Description              Amount
------------------------------------------------------------
1    Comida         Café Starbucks           $5.50
2    Transporte     Uber a la oficina        $12.00
3    Servicios      Recibo de Luz            $45.00
------------------------------------------------------------
                                     TOTAL: $62.50
============================================================
