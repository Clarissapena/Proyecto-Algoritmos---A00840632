#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "mergesort.h"  // 

// Función para leer los datos desde un archivo CSV
std::vector<Transaccion> leerDatos(const std::string& nombreArchivo) {
    std::vector<Transaccion> transacciones;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    while (std::getline(archivo, linea)) {
        Transaccion t;
        size_t pos = 0;

        pos = linea.find(",");
        t.monto = std::stod(linea.substr(0, pos));  // Convertir el primer valor a double (monto)
        linea.erase(0, pos + 1);

        pos = linea.find(",");
        t.categoria = linea.substr(0, pos);  // Segundo valor es la categoría
        linea.erase(0, pos + 1);

        pos = linea.find(",");
        t.tipo = linea.substr(0, pos);  // Tercer valor es el tipo (ingreso/gasto)
        linea.erase(0, pos + 1);

        t.fecha = linea;  // Cuarto valor es la fecha

        transacciones.push_back(t);
    }

    archivo.close();
    return transacciones;
}

// Función para imprimir la lista de transacciones
void imprimirTransacciones(const std::vector<Transaccion>& transacciones) {
    for (const auto& t : transacciones) {
        std::cout << t.tipo << " - " << t.categoria << " - $" << t.monto << " - Fecha: " << t.fecha << std::endl;
    }
}

int main() {
    std::string nombreArchivo = "transacciones.txt";  // Archivo con datos de ingresos y gastos
    std::vector<Transaccion> transacciones = leerDatos(nombreArchivo);

    std::cout << "Transacciones antes de ordenar:\n";
    imprimirTransacciones(transacciones);

    // Ordenar las transacciones usando Merge Sort
    mergeSort(transacciones, 0, transacciones.size() - 1);

    std::cout << "\nTransacciones después de ordenar:\n";
    imprimirTransacciones(transacciones);

    return 0;
}
