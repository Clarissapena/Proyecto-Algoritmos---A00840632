#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include "arboltransacciones.h"
#include "mergesort.h"  // Merge Sort para ordenar las transacciones
#include "meta.h"       // Clase Meta para manejar las metas de ahorro
#include "transaccion.h" // Clase Transaccion para manejar las transacciones

// Función para leer las transacciones desde un archivo TXT
std::vector<Transaccion> leerDatos(const std::string& nombreArchivo) {
    std::vector<Transaccion> transacciones;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    while (std::getline(archivo, linea)) {
        Transaccion t;
        size_t pos = 0;

        // Leer monto
        pos = linea.find(",");
        t.monto = std::stod(linea.substr(0, pos));
        linea.erase(0, pos + 1);

        // Leer categoría
        pos = linea.find(",");
        t.categoria = linea.substr(0, pos);
        linea.erase(0, pos + 1);

        // Leer subcategoría
        pos = linea.find(",");
        t.subcategoria = linea.substr(0, pos);
        linea.erase(0, pos + 1);

        // Leer tipo (ingreso/gasto)
        pos = linea.find(",");
        t.tipo = linea.substr(0, pos);
        linea.erase(0, pos + 1);

        // Leer fecha
        t.fecha = linea;

        // Si es una transacción de meta, cambiamos el tipo a "gasto"
        if (t.categoria == "Meta") {
            t.tipo = "gasto";
        }

        transacciones.push_back(t);
    }

    archivo.close();
    return transacciones;
}

// Función para leer las metas desde un archivo TXT
std::vector<Meta> leerMetas(const std::string& nombreArchivo) {
    std::vector<Meta> metas;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string descripcion, categoria;
        double monto;

        // Leer descripción
        size_t pos = linea.find(",");
        descripcion = linea.substr(0, pos);
        linea.erase(0, pos + 1);

        // Leer monto objetivo
        pos = linea.find(",");
        monto = std::stod(linea.substr(0, pos));
        linea.erase(0, pos + 1);

        // Leer categoría
        categoria = linea;

        // Crear y agregar meta
        metas.emplace_back(descripcion, monto, categoria);
    }

    archivo.close();
    return metas;
}

// Función para obtener categorías únicas utilizando un árbol binario
std::vector<std::string> obtenerCategorias(const std::vector<Transaccion>& transacciones) {
    ArbolTransacciones arbol;

    for (const auto& t : transacciones) {
        if (!t.categoria.empty()) {
            arbol.insertar(t.categoria);
        }
    }

    // Almacenar las categorías ordenadas en un vector
    std::vector<std::string> categoriasOrdenadas;
    arbol.obtenerOrdenados(categoriasOrdenadas);

    return categoriasOrdenadas;
}

// Función para obtener subcategorías únicas utilizando un árbol binario
std::vector<std::string> obtenerSubcategorias(const std::vector<Transaccion>& transacciones) {
    ArbolTransacciones arbol;

    for (const auto& t : transacciones) {
        if (!t.subcategoria.empty()) {
            arbol.insertar(t.subcategoria);
        }
    }

    // Almacenar las subcategorías ordenadas en un vector
    std::vector<std::string> subcategoriasOrdenadas;
    arbol.obtenerOrdenados(subcategoriasOrdenadas);

    return subcategoriasOrdenadas;
}

// Función para calcular el saldo actual
double calcularSaldo(const std::vector<Transaccion>& transacciones) {
    double saldo = 0;
    for (const auto& t : transacciones) {
        if (t.tipo == "ingreso") {
            saldo += t.monto;
        } else if (t.tipo == "gasto") {
            saldo -= t.monto;
        }
    }
    return saldo;
}

// Función para extraer el año de una fecha en formato "YYYY-MM-DD"
int obtenerAnio(const std::string& fecha) {
    return std::stoi(fecha.substr(0, 4));
}

// Función para extraer el mes de una fecha en formato "YYYY-MM-DD"
int obtenerMes(const std::string& fecha) {
    return std::stoi(fecha.substr(5, 2));
}

// Función para visualizar los ingresos ordenados de mayor a menor
void visualizarIngresos(const std::vector<Transaccion>& transacciones) {
    std::cout << "\n--- Visualizar Ingresos Ordenados ---\n";

    // Filtrar las transacciones de tipo "ingreso"
    std::vector<Transaccion> ingresos;
    for (const auto& t : transacciones) {
        if (t.tipo == "ingreso") {
            ingresos.push_back(t);
        }
    }

    // Ordenar los ingresos utilizando MergeSort
    mergeSort(ingresos, 0, ingresos.size() - 1);

    // Mostrar los ingresos ordenados
    std::cout << "Tipo\t\tCategoría\tMonto\t\tFecha\n";
    std::cout << "------------------------------------------------------\n";
    double totalIngresos = 0;
    for (const auto& t : ingresos) {
        totalIngresos += t.monto;
        std::cout << std::left << std::setw(10) << t.tipo 
                  << std::setw(15) << t.categoria 
                  << "$" << std::fixed << std::setprecision(2) << t.monto 
                  << "\t" << t.fecha << std::endl;
    }
    std::cout << "Total Ingresos: $" << std::fixed << std::setprecision(2) << totalIngresos << std::endl;
}

// Función para visualizar gastos por fecha 
void visualizarGastosPorFecha(const std::vector<Transaccion>& transacciones) {
    int opcion;
    std::cout << "\n--- Visualizar Gastos por Fecha ---\n";
    std::cout << "1. Anual\n";
    std::cout << "2. Mensual\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;

    if (opcion == 1) {
        int anio;
        std::cout << "Ingrese el año (YYYY): ";
        std::cin >> anio;

        double totalAnual = 0;
        std::cout << "\n--- Gastos en el Año " << anio << " ---\n";
        std::cout << "Tipo\t\tCategoría\tMonto\t\tFecha\n";
        std::cout << "------------------------------------------------------\n";
        for (const auto& t : transacciones) {
            if (t.tipo == "gasto" && obtenerAnio(t.fecha) == anio) {
                totalAnual += t.monto;
                std::cout << std::left << std::setw(10) << t.tipo 
                          << std::setw(15) << t.categoria 
                          << "$" << std::fixed << std::setprecision(2) << t.monto 
                          << "\t" << t.fecha << std::endl;
            }
        }
        std::cout << "Total Gastos en " << anio << ": $" << std::fixed << std::setprecision(2) << totalAnual << std::endl;
    } 
    else if (opcion == 2) {
        int mes;
        std::cout << "Seleccione el mes (1 = Enero, 2 = Febrero, ..., 12 = Diciembre): ";
        std::cin >> mes;

        // Validar el rango de mes
        while (mes < 1 || mes > 12) {
            std::cout << "Mes inválido. Por favor ingrese un número entre 1 y 12: ";
            std::cin >> mes;
        }

        int anio;
        std::cout << "Ingrese el año (YYYY): ";
        std::cin >> anio;

        double totalMensual = 0;
        std::cout << "\n--- Gastos en el Mes " << mes << " de " << anio << " ---\n";
        std::cout << "Tipo\t\tCategoría\tMonto\t\tFecha\n";
        std::cout << "------------------------------------------------------\n";
        for (const auto& t : transacciones) {
            if (t.tipo == "gasto" && obtenerAnio(t.fecha) == anio && obtenerMes(t.fecha) == mes) {
                totalMensual += t.monto;
                std::cout << std::left << std::setw(10) << t.tipo 
                          << std::setw(15) << t.categoria 
                          << "$" << std::fixed << std::setprecision(2) << t.monto 
                          << "\t" << t.fecha << std::endl;
            }
        }
        std::cout << "Total Gastos en " << mes << "/" << anio << ": $" << std::fixed << std::setprecision(2) << totalMensual << std::endl;
    } 
    else {
        std::cout << "Opción no válida\n";
    }
}

// Función para visualizar gastos
void visualizarGastos(const std::vector<Transaccion>& transacciones) {
    int opcion;
    std::cout << "\n--- Visualizar Gastos ---\n";
    std::cout << "1. Por Categoría\n";
    std::cout << "2. Por Subcategoría\n";
    std::cout << "3. Por Fecha (Anual o Mensual)\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;

    if (opcion == 1) {
        // Obtener categorías únicas ordenadas con el árbol binario
        std::vector<std::string> categorias = obtenerCategorias(transacciones);

        std::cout << "\n--- Categorías Disponibles ---\n";
        for (const auto& categoria : categorias) {
            std::cout << categoria << std::endl;
        }

        std::string categoriaSeleccionada;
        std::cout << "\nIngrese la categoría: ";
        std::cin >> categoriaSeleccionada;

        std::cout << "\n--- Gastos por Categoría ---\n";
        std::cout << "Tipo\t\tCategoría\tMonto\t\tFecha\n";
        std::cout << "------------------------------------------------------\n";
        for (const auto& t : transacciones) {
            if (t.categoria == categoriaSeleccionada && t.tipo == "gasto") {
                std::cout << std::left << std::setw(10) << t.tipo 
                          << std::setw(15) << t.categoria 
                          << "$" << std::fixed << std::setprecision(2) << t.monto 
                          << "\t" << t.fecha << std::endl;
            }
        }
    } else if (opcion == 2) {
        // Obtener subcategorías únicas ordenadas con el árbol binario
        std::vector<std::string> subcategorias = obtenerSubcategorias(transacciones);

        std::cout << "\n--- Subcategorías Disponibles (Ordenadas) ---\n";
        for (const auto& subcategoria : subcategorias) {
            std::cout << subcategoria << std::endl;
        }

        std::string subcategoriaSeleccionada;
        std::cout << "\nIngrese la subcategoría: ";
        std::cin >> subcategoriaSeleccionada;

        std::cout << "\n--- Gastos por Subcategoría ---\n";
        std::cout << "Tipo\t\tSubcategoría\tMonto\t\tFecha\n";
        std::cout << "------------------------------------------------------\n";
        for (const auto& t : transacciones) {
            if (t.subcategoria == subcategoriaSeleccionada && t.tipo == "gasto") {
                std::cout << std::left << std::setw(10) << t.tipo 
                          << std::setw(15) << t.subcategoria 
                          << "$" << std::fixed << std::setprecision(2) << t.monto 
                          << "\t" << t.fecha << std::endl;
            }
        }
    } else if (opcion == 3) {
        visualizarGastosPorFecha(transacciones);
    } else {
        std::cout << "Opción no válida\n";
    }
}

// Función para mostrar el saldo actual
void mostrarSaldoActual(const std::vector<Transaccion>& transacciones) {
    std::cout << "\nSaldo Actual: $" << std::fixed << std::setprecision(2) << calcularSaldo(transacciones) << std::endl;
}

// Función para mostrar metas de ahorro
void mostrarMetas(std::vector<Meta>& metas, const std::vector<Transaccion>& transacciones) {
    std::cout << "\n--- Metas de Ahorro ---\n";
    std::cout << "Descripción\t\tObjetivo\tAhorro Actual\tRestante\n";
    std::cout << "-------------------------------------------------------------\n";

    for (auto& meta : metas) {
        double acumulado = meta.calcularAcumulado(transacciones);
        double restante = meta.calcularRestante();

        std::cout << std::left << std::setw(20) << meta.getDescripcion()
                  << "$" << std::fixed << std::setprecision(2) << meta.getMontoObjetivo()
                  << "\t$" << std::fixed << std::setprecision(2) << acumulado
                  << "\t" << (restante > 0 ? "$" + std::to_string(restante) : "Completado") << std::endl;
    }
}

// Función para generar un reporte anual de todos los gastos e ingresos y escribirlo en un archivo
void generarReporteAnual(const std::vector<Transaccion>& transacciones) {
    std::ofstream archivo("reporte_anual.txt");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de reporte anual.\n";
        return;
    }

    double totalIngresos = 0;
    double totalGastos = 0;
    archivo << "--- Reporte Anual de Ingresos y Gastos ---\n";
    archivo << "Tipo\t\tCategoría\tSubcategoría\tMonto\t\tFecha\n";
    archivo << "------------------------------------------------------------\n";

    for (const auto& t : transacciones) {
        archivo << std::left << std::setw(10) << t.tipo
                << std::setw(15) << t.categoria
                << std::setw(15) << t.subcategoria
                << "$" << std::fixed << std::setprecision(2) << t.monto
                << "\t" << t.fecha << "\n";

        // Acumular total de ingresos y gastos
        if (t.tipo == "ingreso") {
            totalIngresos += t.monto;
        } else if (t.tipo == "gasto") {
            totalGastos += t.monto;
        }
    }

    archivo << "\nTotal de Ingresos: $" << std::fixed << std::setprecision(2) << totalIngresos << "\n";
    archivo << "Total de Gastos: $" << std::fixed << std::setprecision(2) << totalGastos << "\n";
    archivo << "Balance Anual: $" << std::fixed << std::setprecision(2) << (totalIngresos - totalGastos) << "\n";
    archivo.close();

    std::cout << "Reporte anual generado en 'reporte_anual.txt'.\n";
}

//Menu del programaaaaa
int main() {
    std::vector<Transaccion> transacciones = leerDatos("transacciones.txt");
    std::vector<Meta> metas = leerMetas("metas.txt");

    // Ordenar las transacciones por monto (de mayor a menor) antes de mostrar los gastos o ingresos
    mergeSort(transacciones, 0, transacciones.size() - 1);

    int opcion;
    do {
        std::cout << "\n--- Menú Principal ---\n";
        std::cout << "1. Visualizar gastos\n";
        std::cout << "2. Mostrar saldo actual\n";
        std::cout << "3. Mostrar metas de ahorro\n";
        std::cout << "4. Generar reporte anual\n";
        std::cout << "5. Mostrar ingresos\n"; // Nueva opción para mostrar ingresos
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                visualizarGastos(transacciones);
                break;
            case 2:
                mostrarSaldoActual(transacciones);
                break;
            case 3:
                mostrarMetas(metas, transacciones);
                break;
            case 4:
                generarReporteAnual(transacciones); 
                break;
            case 5:
                visualizarIngresos(transacciones); 
                break;
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}