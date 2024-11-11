# WISE FINANCE
Wise Finance es una aplicación de gestión de finanzas personales diseñada para ayudar a los usuarios a controlar sus ingresos, gastos y metas de ahorro. La aplicación permite registrar y clasificar transacciones financieras, proporcionando una visión clara de los gastos e ingresos organizados de mayor a menor según su monto, lo que facilita la visualización y análisis de datos. Una de sus funciones clave es definir metas de ahorro y mostrar el progreso hacia ellas. Wise Finance incluye algoritmos de ordenamiento como MergeSort para ordenar las transacciones de manera eficiente, permitiendo gestionar grandes volúmenes de datos y mejorar la experiencia del usuario.

## Descripción del avance 1
Lo que se muestra a continuación en este primer avance es como se ha implementado la función básica para registrar los ingresos y los gastos. Se creo un programa que permite al usuario ingresar manualmente sus datos financieros, así como definir una meta financiera. El programa además contiene un algoritmo de ordenamiento, el cual se encarga de ornedar los ingresos y gastos de mayor a menor para obtener una mayor visualización de los datos financieros de usuario. 
En este primer avance, he implementado la funcionalidad básica que permite:
1. Ingresar datos de ingresos y gastos con sus categorías correspondientes.
2. Guardar y procesar estas transacciones en una lista.
3. Utilizar el algoritmo Merge Sort para ordenar las transacciones de mayor a menor según el monto.
4. Mostrar la lista de transacciones antes y después de ser ordenadas.
El algoritmo de Quicksort fue seleccionado debido a su eficiencia y capacidad para manejar grandes cantidades de datos, lo que es crucial en la gestión de finanzas personales.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp`

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./a.out`

## Descripción de las entradas del avance de proyecto
El sistema recibe entradas de datos financieros a través de un archivo CSV o entradas manuales. Las entradas incluyen los siguientes campos:
Ingreso: Monto de ingreso, su categoría (salario, freelance, etc.), y la fecha.
Gasto: Monto de gasto, categoría (alimentación, transporte, entretenimiento, etc.), y la fecha.

## Descripción de las salidas del avance de proyecto
Las salidas del proyecto en esta fase incluyen:
Saldo disponible: El saldo que queda después de deducir los gastos de los ingresos.
Resumen financiero: Listado de ingresos y gastos clasificados por categoría, mostrando el porcentaje de gastos en cada área.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Análisis de complejidad de componentes
#### 1.	Registro de transacciones
Inserción (addTransaction):      
Mejor caso: O(1), ya que se agrega la transacción al final de la lista sin necesidad de ajustes.   
Caso promedio y peor caso: O(1), la operación de inserción es constante, ya que siempre se realiza en la misma posición.   
Acceso a transacciones (viewTransactions):   
Complejidad: O(n), ya que en todos los casos se recorre la lista de transacciones para mostrar cada elemento.
#### 2.	Ordenamiento de transacciones (MergeSort)
Complejidad de ordenamiento:
Mejor, promedio y peor caso: O(n log n), MergeSort siempre realiza las operaciones de división y combinación de manera constante, independientemente de la disposición inicial de los datos.
Espacio adicional: O(n) para almacenar sublistas temporales.
#### 3.	Funcionalidades de la clase Meta
Cálculo de acumulado (calcularAcumulado):
Complejidad: O(m), donde m es el número de transacciones. La función recorre todas las transacciones para calcular el monto acumulado para una meta específica.
Cálculo de restante (calcularRestante):
Complejidad: O(1), ya que esta función realiza una operación de resta y comparación constante, sin bucles o estructuras adicionales.
Obtener información de la meta (getDescripcion, getMontoObjetivo):
Complejidad: O(1), cada uno de estos métodos retorna un valor sin procesamiento adicional.
#### 4.	Visualización de transacciones ordenadas
Impresión de lista (printSortedTransactions):
Complejidad: O(n), recorre toda la lista de transacciones para imprimir cada elemento.
#### 5.	Complejidad global del programa
La complejidad general del programa está dominada por las operaciones de ordenamiento y el cálculo del acumulado para las metas. La complejidad final, considerando el flujo completo, es O(n log n + m), siendo n el número de transacciones y m el número de transacciones relacionadas con metas en el cálculo del acumulado.


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En el proyecto se puede ver como se ha implementado en el código de forma correcta, con la función de ordenamiento para los datos de ingresos y gastos, mostrando una lista de transacciones antes y después del ordenamiento. La decisión de usar Merge Sort fue la más adecuada para resolver el problema del proyecto, maximizando el rendimiento y minimizando el uso de recursos.
