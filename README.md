# WISE FINANCE
El proyecto que realizare, es el desarrollo de un programa que permita a los usuarios gestionar sus finanzas personales de manera eficiente. Los usuarios podrán registrar sus ingresos y gastos, también asignarán presupuestos mensuales, además establecerán metas de ahorro. Esto ayudara al usuario a obtener un análisis de su comportamiento financiero, ayudándole a notas cuales son sus hábitos de consumo y tomar medidas al respecto para mejorar su estabilidad financiera. 

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

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp`
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
Merge Sort tiene una complejidad de O(nlogn) en todos los casos (mejor, promedio y peor), debido a que siempre divide el arreglo en mitades y luego los combina. Es un algoritmo estable, lo que significa que mantiene el orden de elementos iguales, y es ideal para conjuntos de datos grandes y donde se requiere consistencia en el tiempo de ejecución.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En el proyecto se puede ver como se ha implementado en el código de forma correcta, con la función de ordenamiento para los datos de ingresos y gastos, mostrando una lista de transacciones antes y después del ordenamiento. La decisión de usar Merge Sort fue la más adecuada para resolver el problema del proyecto, maximizando el rendimiento y minimizando el uso de recursos.
