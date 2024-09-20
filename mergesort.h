#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
#include <string>

// Estructura para almacenar cada transacción (ingresos y gastos)
struct Transaccion {
    double monto;
    std::string categoria;
    std::string tipo;
    std::string fecha;
};

// Función para combinar dos sub-vectores
void merge(std::vector<Transaccion>& transacciones, int izquierda, int mitad, int derecha) {
    int n1 = mitad - izquierda + 1;
    int n2 = derecha - mitad;

    // Vectores temporales
    std::vector<Transaccion> izquierdaTrans(n1);
    std::vector<Transaccion> derechaTrans(n2);

    // Copiar datos a los vectores temporales
    for (int i = 0; i < n1; i++)
        izquierdaTrans[i] = transacciones[izquierda + i];
    for (int j = 0; j < n2; j++)
        derechaTrans[j] = transacciones[mitad + 1 + j];

    // Mezclar los vectores temporales de nuevo en transacciones[izquierda..derecha]
    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {
        if (izquierdaTrans[i].monto >= derechaTrans[j].monto) {
            transacciones[k] = izquierdaTrans[i];
            i++;
        } else {
            transacciones[k] = derechaTrans[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes
    while (i < n1) {
        transacciones[k] = izquierdaTrans[i];
        i++;
        k++;
    }

    while (j < n2) {
        transacciones[k] = derechaTrans[j];
        j++;
        k++;
    }
}

// Función recursiva de Merge Sort
void mergeSort(std::vector<Transaccion>& transacciones, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int mitad = izquierda + (derecha - izquierda) / 2;

        // Ordenar primero las mitades
        mergeSort(transacciones, izquierda, mitad);
        mergeSort(transacciones, mitad + 1, derecha);

        // Combinar las mitades ordenadas
        merge(transacciones, izquierda, mitad, derecha);
    }
}

#endif // MERGESORT_H