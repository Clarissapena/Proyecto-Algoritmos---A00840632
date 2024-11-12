#ifndef ARBOLTRANSACCIONES_H
#define ARBOLTRANSACCIONES_H

#include <iostream>
#include <string>
#include <vector>


// Estructura del nodo para el árbol binario
struct Nodo {
    std::string valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(const std::string& val) : valor(val), izquierda(nullptr), derecha(nullptr) {}
};

// Clase para el árbol binario
class ArbolTransacciones {
public:
    Nodo* raiz;

    ArbolTransacciones() : raiz(nullptr) {}

    // Función para insertar un valor en el árbol
    void insertar(const std::string& valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    // Función para mostrar el árbol en inorden (ordenado)
    void inorden() const {
        inordenRecursivo(raiz);
    }

    // Función para almacenar los valores del árbol en un vector (ordenado)
    void obtenerOrdenados(std::vector<std::string>& valores) const {
        obtenerOrdenadosRecursivo(raiz, valores);
    }

private:
    Nodo* insertarRecursivo(Nodo* nodo, const std::string& valor) {
        if (nodo == nullptr) {
            return new Nodo(valor);
        }
        if (valor < nodo->valor) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->valor) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }
        return nodo;
    }

    void inordenRecursivo(Nodo* nodo) const {
        if (nodo != nullptr) {
            inordenRecursivo(nodo->izquierda);
            std::cout << nodo->valor << std::endl;
            inordenRecursivo(nodo->derecha);
        }
    }

    void obtenerOrdenadosRecursivo(Nodo* nodo, std::vector<std::string>& valores) const {
        if (nodo != nullptr) {
            obtenerOrdenadosRecursivo(nodo->izquierda, valores);
            valores.push_back(nodo->valor);
            obtenerOrdenadosRecursivo(nodo->derecha, valores);
        }
    }
};

#endif
