#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <string>

struct Transaccion {
    double monto;
    std::string categoria;
    std::string subcategoria; // Nueva subcategoría
    std::string tipo;  // ingreso o gasto
    std::string fecha;
    Transaccion* siguiente;
    Transaccion* anterior;
};

class ListaTransacciones {
private:
    Transaccion* head;
    Transaccion* tail;

public:
    ListaTransacciones();
    ~ListaTransacciones();
    void agregarTransaccion(double monto, const std::string& categoria, const std::string& subcategoria, const std::string& tipo, const std::string& fecha);
    void eliminarTransaccion(const std::string& fecha);
    void imprimirTransacciones();
    // Funciones para ordenar
    void ordenarPorMonto();
    void ordenarPorCategoria();
};

#endif // TRANSACCION_H

