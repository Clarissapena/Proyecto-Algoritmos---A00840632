# WISE FINANCE
Wise Finance es una aplicación de gestión de finanzas personales diseñada para ayudar a los usuarios a controlar sus ingresos, gastos y metas de ahorro. La aplicación permite registrar y clasificar transacciones financieras, proporcionando una visión clara de los gastos e ingresos organizados de mayor a menor según su monto, lo que facilita la visualización y análisis de datos. Una de sus funciones clave es definir metas de ahorro y mostrar el progreso hacia ellas. Wise Finance incluye algoritmos de ordenamiento como MergeSort para ordenar las transacciones de manera eficiente, permitiendo gestionar grandes volúmenes de datos y mejorar la experiencia del usuario.

## Descripción del avance 1
Lo que se muestra a continuación en este primer avance es como se ha implementado la función básica para registrar los ingresos y los gastos. Se creo un programa que permite al usuario ingresar manualmente sus datos financieros, así como definir una meta financiera. El programa además contiene un algoritmo de ordenamiento, el cual se encarga de ornedar los ingresos y gastos de mayor a menor para obtener una mayor visualización de los datos financieros de usuario. 
En este primer avance, he implementado la funcionalidad básica que permite:
1. Ingresar datos de ingresos y gastos con sus categorías correspondientes.
2. Guardar y procesar estas transacciones en una lista.
3. Utilizar el algoritmo Merge Sort para ordenar las transacciones de mayor a menor según el monto.
4. Mostrar la lista de transacciones antes y después de ser ordenadas.

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:
g++ -std=c++11 main.cpp
`./a.out`

## Descripción de las entradas del avance de proyecto
Para las entradas desde archivos CSV, el sistema puede procesar archivos que contengan múltiples transacciones, donde cada fila del archivo representa una transacción con los siguientes campos: monto, categoría y fecha. El archivo CSV es leído y las transacciones se agregan automáticamente al sistema, facilitando la carga de grandes volúmenes de datos financieros sin necesidad de ingreso manual. Esta funcionalidad ya ha sido implementada y se utiliza un parser que procesa el CSV fila por fila, validando los datos antes de insertarlos en la lista de transacciones. 

## Descripción de las salidas del avance de proyecto
El sistema de Wise Finance proporciona un resumen financiero que clasifica los gastos según su categoría y muestra el porcentaje de gasto en cada área. A continuación, se describe el proceso para calcular este porcentaje:   
**Suma total de los gastos:** El sistema primero calcula el total de todos los gastos registrados por el usuario. Esta suma es la base para determinar qué proporción representa cada categoría sobre el total.   
**Cálculo del porcentaje por categoría:** Para cada categoría de gasto (como alimentación, transporte, entretenimiento, etc.), se suman todos los montos de las transacciones asociadas. Luego, se calcula el porcentaje de gasto dividiendo el total de cada categoría entre el total de todos los gastos y multiplicando por 100.   
**Visualización del resumen:** Aunque en esta primera fase el sistema solo muestra los porcentajes en formato de texto, el plan es implementar una visualización gráfica en fases futuras. Las gráficas ayudarán a los usuarios a comprender mejor la distribución de sus gastos. Se prevé el uso de gráficas de barras o gráficas de pastel para mostrar de manera clara y visual qué proporción del presupuesto se gasta en cada categoría.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Aquí veremos la complejidad de las funcionalidades más importantes de mi proyecto :)
#### 1.	La complejidad al hacer el registro de transacciones
He almacenando las transacciones en una estructura de lista doblemente enlazada (Transaccion con punteros siguiente y anterior), lo cual fue una buena elección porque necesito navegar tanto hacia adelante como hacia atrás a través de las transacciones.
*Inserción (addTransaction)*      
Mejor caso: *O(1)*, ya que se agrega la transacción al final de la lista sin necesidad de ajustes.   
Caso promedio y peor caso: *O(1)*, la operación de inserción es constante, ya que siempre se realiza en la misma posición.   
*Acceso a transacciones (viewTransactions)*     
Complejidad: *O(n)*, ya que en todos los casos se recorre la lista de transacciones para mostrar cada elemento.
#### 2.	Ordenamiento de transacciones (MergeSort)
*Complejidad de ordenamiento:*   
Mejor, promedio y peor caso: *O(n log n)*, MergeSort siempre realiza las operaciones de división y combinación de manera constante, independientemente de la disposición inicial de los datos.   
Elección del algoritmo de ordedamiento:   
MergeSort tiene una complejidad temporal de *O(n log n)* en el mejor, promedio y peor caso, lo cual es particularmente útil en aplicaciones de finanzas personales, donde el número de transacciones puede crecer considerablemente. Esta eficiencia garantiza que el rendimiento del sistema se mantenga estable incluso con volúmenes elevados de datos.
A diferencia de algoritmos como QuickSort, cuyo rendimiento puede degradarse en conjuntos de datos que están casi ordenados o presentan un patrón específico, MergeSort mantiene su eficiencia sin importar la disposición inicial de los datos. Esto es útil en Wise Finance, donde las transacciones pueden no seguir un orden particular al ser registradas.   
MergeSort es la mejor opción para Wise Finance ya que equilibra eficiencia, estabilidad, seguridad en la manipulación de datos y consistencia en el rendimiento, adaptándose bien al entorno de manejo de transacciones financieras.
#### 3.	La complejidad de mi clase Meta
*Cálculo de acumulado (calcularAcumulado)*   
Complejidad: *O(m)*, donde m es el número de transacciones. La función recorre todas las transacciones para calcular el monto acumulado para una meta específica.   
*Cálculo de restante (calcularRestante)*   
Complejidad: *O(1)*, ya que esta función realiza una operación de resta y comparación constante, sin bucles o estructuras adicionales.   
*Obtener información de la meta (getDescripcion, getMontoObjetivo)*      
Complejidad: *O(1)*, cada uno de estos métodos retorna un valor sin procesamiento adicional.
#### 4.	Visualización de transacciones ordenadas
*Impresión de lista (printSortedTransactions)*   
Complejidad: *O(n)*, recorre toda la lista de transacciones para imprimir cada elemento. 
#### 5. Complejidad de mi arbol binario:
La inserción en un árbol binario de búsqueda tiene una complejidad de O(log n) en el mejor de los casos (cuando el árbol está balanceado). Sin embargo, si el árbol se desbalancea, la complejidad podría llegar a ser O(n). En el peor caso, cuando el árbol se convierte en una lista enlazada, cada inserción puede tomar O(n).   
**Recorrido inorden (obtenerOrdenados)**: El recorrido inorden de un árbol binario tiene una complejidad de O(n), donde n es el número de nodos (en este caso, el número de categorías o subcategorías). Esto es porque cada nodo del árbol se visita exactamente una vez durante el recorrido.   

#### 6.	Complejidad global del programa
La complejidad general del programa está dominada por las operaciones de ordenamiento y el cálculo del acumulado para las metas. La complejidad final, considerando el flujo completo, es *O(n log n + m)*, siendo n el número de transacciones y m el número de transacciones relacionadas con metas en el cálculo del acumulado.


### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para ordenar las transacciones de manera eficiente, se seleccionó el algoritmo MergeSort. Este algoritmo es adecuado para Wise Finance ya que me proporciona un ordenamiento con una complejidad de O(n log n), independientemente de la disposición inicial de las transacciones. Las implementaciones del algoritmo se encuentran en el archivo mergesort.h.   
##### Llamada a MergeSort para ordenar las transacciones, en la línea 452 del main, donde se ordenan las transacciones antes de mostrarlas:
mergeSort(transacciones, 0, transacciones.size() - 1);
##### Además, el ordenamiento para visualizar ingresos se realiza en Línea 382 dentro de la función visualizarIngresos:
mergeSort(ingresos, 0, ingresos.size() - 1);   

#### Mi lista estándar para almacenar las transacciones
Utilicé una estructura de lista estándar para almacenar las transacciones de ingresos y gastos. Esta lista permite agregar transacciones en el orden en que son registradas y acceder a ellas en secuencia para su análisis y visualización. La estructura es adecuada para almacenar transacciones debido a su flexibilidad y facilidad de manipulación, ya que la adición y el acceso a los datos financieros se realizan en tiempo constante, O(1). Las funciones de inserción y visualización de transacciones se encuentran en el archivo main.cpp en las líneas correspondientes.
##### Líneas relevantes:   
##### std::vector<Transaccion> transacciones; (Línea 16): Aquí se declara la lista de transacciones.   
##### transacciones.push_back(t); (Líneas 28-33): Se insertan las transacciones en la lista.   

#### Mi clase para manejar las metas financieras
Para la gestión de metas de ahorro, se implementó la clase Meta, que organiza cada meta como un objeto separado con propiedades de descripción, monto objetivo y monto acumulado. Esta clase permite calcular el progreso de cada meta a partir de las transacciones asociadas, brindando una manera clara y estructurada de manejar y actualizar el avance de las metas. La clase Meta y sus métodos para calcular el acumulado y el monto restante se encuentran en meta.h.
##### Líneas relevantes en meta.h:   
##### Meta(const std::string& desc, double monto, const std::string& cat) (Línea 18): Constructor de la clase Meta.   
##### double calcularAcumulado(const std::vector<Transaccion>& transacciones) (Líneas 23-29): Método que calcula el monto acumulado.   
##### double calcularRestante() const (Líneas 31-35): Método que calcula el monto restante de la meta.   

#### Ordenamineto de las transacciones por categoría
Utilicé un árbol binario (ArbolTransacciones) para almacenar y ordenar categorías y subcategorías es un enfoque eficaz para garantizar la unicidad y la fácil navegación.
Mi árbol contiene lo siguiente: 
Cada nodo del árbol contiene:
valor: una cadena de texto que representa la categoría o subcategoría.
izquierda y derecha: punteros a los nodos hijos izquierdo y derecho, respectivamente.
Y estás son las funciones más importantes:    
*Insertar categorías y subcategorías:* Cada vez que se añade una transacción, se extraen su categoría o subcategoría y se insertan en el árbol correspondiente.      
Esto se encuentra en las líneas del código: 10 - 30    
*Obtener las categorías y subcategorías ordenadas:* Para mostrar las categorías o subcategorías de las transacciones ordenadas, el programa llama a la función obtenerOrdenados, que recorre el árbol en orden y las almacena en un vector. Esto permite que las categorías o subcategorías se muestren de forma ordenada.   
Esto se encuentra en las líneas del código: 10 - 60   
*Filtrado por categorías o subcategorías:* En la función visualizarGastos, se pueden mostrar los gastos por categoría o subcategoría. El árbol binario se utiliza para obtener las categorías y subcategorías únicas y ordenadas, y luego se filtran las transacciones según la opción seleccionada por el usuario.   
Esto se encuentra en las líneas del código del main: 90 - 135   

### SICT0303: Implementa acciones científicas
#### Uso y Funcionamiento del Árbol Binario en el Código
El árbol binario que se utiliza en el código es una estructura de datos para almacenar valores de tipo std::string (en este caso, categorías y subcategorías de las transacciones) de manera ordenada. Este árbol permite realizar operaciones de inserción y recorrido en orden, que son útiles para manejar los datos de forma eficiente.
En el código que has proporcionado, el árbol binario se utiliza en las siguientes funciones:
##### Obtener categorías únicas ordenadas (obtenerCategorias):
*Líneas donde se usa el árbol:*   
Línea 35: ArbolTransacciones arbol; - Se crea una instancia del árbol binario.   
Línea 37: arbol.insertar(t.categoria); - Las categorías de las transacciones se insertan en el árbol.   
Línea 40: arbol.obtenerOrdenados(categoriasOrdenadas); - Después de insertar las categorías, se obtienen las categorías ordenadas mediante un recorrido inorden.   
##### Obtener subcategorías únicas ordenadas (obtenerSubcategorias):
*Líneas donde se usa el árbol:*   
Línea 44: ArbolTransacciones arbol; - Se crea una nueva instancia del árbol binario.   
Línea 46: arbol.insertar(t.subcategoria); - Se insertan las subcategorías de las transacciones en el árbol.   
Línea 49: arbol.obtenerOrdenados(subcategoriasOrdenadas); - Se recuperan las subcategorías ordenadas mediante el recorrido inorden.   



#### Conclusiones
**1. Análisis y selección de algoritmos adecuados**      
Uno de los principales aspectos de este proyecto ha sido la elección de algoritmos de ordenamiento eficientes, como MergeSort, que garantizan una buena gestión de grandes volúmenes de datos, manteniendo un rendimiento estable.   
**2. Estructuración y manejo eficiente de datos**   
Para gestionar las categorías y subcategorías de las transacciones financieras, se optó por un árbol binario de búsqueda en lugar de otras estructuras como un std::set. La decisión de utilizar un árbol binario fue clave para garantizar flexibilidad y eficiencia al ordenar y recuperar datos, como se menciona en el análisis de complejidad de inserción y recorrido.    
**3. Integración de diferentes métodos de entrada y salida** 
El proyecto contempla la posibilidad de ingresar datos tanto de forma manual como desde archivos CSV. Esta funcionalidad demuestra una comprensión del manejo de datos desde diferentes fuentes, lo cual es esencial en proyectos que aspiran a ofrecer flexibilidad al usuario. Además, se ha implementado un sistema de procesamiento para validar y almacenar estos datos correctamente, garantizando que el sistema pueda manejar diferentes tipos de entradas sin afectar su rendimiento o integridad.   
**4. Organización del proyecto y documentación**   
El desarrollo de un buen proyecto también se refleja en la organización clara del código y la documentación adecuada. En este caso, se han seguido buenas prácticas de programación, como la separación en módulos y clases para organizar las funcionalidades relacionadas con transacciones y metas financieras. Además, se ha documentado cada una de las decisiones clave del proyecto, explicando el razonamiento detrás de la elección de estructuras de datos y algoritmos, lo que facilita el mantenimiento y la comprensión del sistema por parte de otros desarrolladores o usuarios avanzados.     

Este proyecto de Wise Finance me ha tomado bastante tiempo y dedicación, pero me ha encantado ver cómo va tomando forma. Desde el análisis de las soluciones hasta la implementación de funciones, me he esforzado en cada detalle. He tenido que tomar decisiones importantes sobre qué estructuras de datos y algoritmos usar, y aunque fue un reto, estoy orgullosa del resultado. Siento que el proyecto no solo funciona bien, sino que además es claro y útil para el usuario final, lo cual es muy gratificante.








