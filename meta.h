#ifndef META_H
#define META_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "transaccion.h"

class Meta {
private:
    std::string descripcion;
    double montoObjetivo;
    double montoAhorrado;
    std::string categoria;

public:
    // Constructor
    Meta(const std::string& desc, double monto, const std::string& cat)
        : descripcion(desc), montoObjetivo(monto), montoAhorrado(0), categoria(cat) {}

    // Método para calcular el monto acumulado basado en las transacciones
    double calcularAcumulado(const std::vector<Transaccion>& transacciones) {
        montoAhorrado = 0; // Reinicia el ahorro acumulado
        for (const auto& t : transacciones) {
            if (t.tipo == "gasto" && t.categoria == "Meta" && t.subcategoria == descripcion) {
                montoAhorrado += t.monto;
            }
        }
        return montoAhorrado;
    }

    // Método para calcular el monto restante
    double calcularRestante() const {
        return (montoObjetivo - montoAhorrado > 0) ? montoObjetivo - montoAhorrado : 0;
    }

    // Métodos para obtener información de la meta
    const std::string& getDescripcion() const { return descripcion; }
    double getMontoObjetivo() const { return montoObjetivo; }
};

#endif // META_H




