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

## Desarrollo de competencias :sparkles:  

### SICT0301: Evalúa los componentes-----------------------------------------------------------------------
*Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.*:question:
*Aquí veremos la complejidad de las funcionalidades más importantes de mi proyecto :)*

#### Complejidad de mi algoritmo y estructura de datos :rocket:  
#### 1.	Complejidad de Mergesort (Mi algoritmo de ordenamiento)
*Complejidad de ordenamiento:*   
Mejor, promedio y peor caso: *O(n log n)*, MergeSort siempre realiza las operaciones de división y combinación de manera constante, independientemente de la disposición inicial de los datos.   
Elección del algoritmo de ordedamiento:   
MergeSort tiene una complejidad temporal de *O(n log n)* en el mejor, promedio y peor caso, lo cual es particularmente útil en aplicaciones de finanzas personales, donde el número de transacciones puede crecer considerablemente. Esta eficiencia garantiza que el rendimiento del sistema se mantenga estable incluso con volúmenes elevados de datos.
A diferencia de algoritmos como QuickSort, cuyo rendimiento puede degradarse en conjuntos de datos que están casi ordenados o presentan un patrón específico, MergeSort mantiene su eficiencia sin importar la disposición inicial de los datos. Esto es útil en Wise Finance, donde las transacciones pueden no seguir un orden particular al ser registradas.   
MergeSort es la mejor opción para Wise Finance ya que equilibra eficiencia, estabilidad, seguridad en la manipulación de datos y consistencia en el rendimiento, adaptándose bien al entorno de manejo de transacciones financieras.

#### 2. Complejidad de mi arbol binario:
*Función insertar*
**Mejor caso (O(log n)):** El árbol está balanceado, por lo que se recorre solo hasta la mitad de los nodos en cada nivel.
**Promedio (O(log n)):** El árbol está medianamente balanceado.
**Peor caso (O(n)):** El árbol está desbalanceado (se convierte en lista), y hay que recorrer todos los nodos.
*Función inorden*
**Mejor, Promedio y Peor caso (O(n)):** Se deben visitar todos los nodos del árbol en un recorrido en inorden, independientemente de su estructura.
*Función obtenerOrdenados*
**Mejor, Promedio y Peor caso (O(n)):** Similar a inorden, recorre todo el árbol para almacenar los valores en un vector.

#### Complejidad de las funciones de mi programa :rocket:  
#### 1.	La complejidad al hacer el registro de transacciones y el uso de mi lista
Lectura del archivo:   
El bucle while (std::getline(inputFile, line)) recorre el archivo línea por línea.   
La complejidad total del proceso (lectura) a O(n log n) en la práctica.
He almacenando las transacciones en una estructura de lista doblemente enlazada (Transaccion con punteros siguiente y anterior), lo cual fue una buena elección porque necesito navegar tanto hacia adelante como hacia atrás a través de las transacciones.
*Inserción (addTransaction)*      
Mejor caso: *O(1)*, ya que se agrega la transacción al final de la lista sin necesidad de ajustes.   
Caso promedio y peor caso: *O(1)*, la operación de inserción es constante, ya que siempre se realiza en la misma posición.   
*Acceso a transacciones (viewTransactions)*     
Complejidad: *O(n)*, ya que en todos los casos se recorre la lista de transacciones para mostrar cada elemento.
#### 2.	La complejidad de mi clase Meta
*Cálculo de acumulado (calcularAcumulado)*   
Complejidad: *O(m)*, donde m es el número de transacciones. La función recorre todas las transacciones para calcular el monto acumulado para una meta específica.   
*Cálculo de restante (calcularRestante)*   
Complejidad: *O(1)*, ya que esta función realiza una operación de resta y comparación constante, sin bucles o estructuras adicionales.   
*Obtener información de la meta (getDescripcion, getMontoObjetivo)*      
Complejidad: *O(1)*, cada uno de estos métodos retorna un valor sin procesamiento adicional.
#### 3.	Visualización de transacciones ordenadas
*Impresión de lista (printSortedTransactions)*   
Complejidad: *O(n)*, recorre toda la lista de transacciones para imprimir cada elemento. 

#### Complejidad global del programa :robot:  
La complejidad general del programa está dominada por las operaciones de ordenamiento y el cálculo del acumulado para las metas. La complejidad final, considerando el flujo completo, es *O(n log n + m)*, siendo n el número de transacciones y m el número de transacciones relacionadas con metas en el cálculo del acumulado.


### SICT0302: Toma decisiones-------------------------------------------------------------------
*Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.* :question:
#### Mi algoritmo de ordenamiento :rocket:
Para ordenar las transacciones de manera eficiente, se seleccionó el algoritmo MergeSort. Este algoritmo es adecuado para Wise Finance ya que me proporciona un ordenamiento con una complejidad de O(n log n), independientemente de la disposición inicial de las transacciones. Las implementaciones del algoritmo se encuentran en el archivo mergesort.h.   
##### Llamada a MergeSort para ordenar las transacciones, en la línea 452 del main, donde se ordenan las transacciones antes de mostrarlas:
mergeSort(transacciones, 0, transacciones.size() - 1);
##### Además, el ordenamiento para visualizar ingresos se realiza en Línea 382 dentro de la función visualizarIngresos:
mergeSort(ingresos, 0, ingresos.size() - 1);   

*Selecciona una estructura de datos adecuada al problema y la usa correctamente.* :question:
#### Mi estructura de datos :rocket:
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

#### Mi lista estándar para almacenar las transacciones :rocket:
Utilicé una estructura de lista estándar para almacenar las transacciones de ingresos y gastos. Esta lista permite agregar transacciones en el orden en que son registradas y acceder a ellas en secuencia para su análisis y visualización. La estructura es adecuada para almacenar transacciones debido a su flexibilidad y facilidad de manipulación, ya que la adición y el acceso a los datos financieros se realizan en tiempo constante, O(1). Las funciones de inserción y visualización de transacciones se encuentran en el archivo main.cpp en las líneas correspondientes.
##### Líneas relevantes:   
##### std::vector<Transaccion> transacciones; (Línea 16): Aquí se declara la lista de transacciones.   
##### transacciones.push_back(t); (Líneas 28-33): Se insertan las transacciones en la lista.     
 

### SICT0303: Implementa acciones científicas
*Implementa mecanismos para consultar información de las estructras correctos.* :question:


*Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.* :question:
#### Mi lectura de archivos
Decicí utilizar un vector para almacenar las transacciones porque es una solución simple y clara. Los vectores son fáciles de usar y proporcionan un acceso rápido y eficiente a los elementos, lo que hace que el código sea más legible y fácil de mantener. Esto se puede ver en las líneas 13 a 88 del archivo main.cpp. 
Las funciones leerDatos y leerMetas leen datos desde archivos para cargarlos. Ambas funciones abren un archivo en modo lectura y leen línea por línea. En leerDatos, se extraen y convierten los valores de las transacciones (como monto, categoría y fecha) y se almacenan en un vector de objetos Transaccion. En leerMetas, se procesan las metas de ahorro (como descripción, monto objetivo y categoría) y se almacenan en un vector de objetos Meta. Los datos se dividen usando un delimitador (como la coma) y se convierten a los tipos adecuados. Estas funciones permiten persistir los datos entre ejecuciones del programa.
En el caso del Arbolbinario funciona de la siguiente manera:   
La lectura de las transacciones se hace a través de las funciones obtenerCategorias y obtenerSubcategorias.   
Estas funciones reciben un vector de transacciones, iteran sobre ellas y insertan las categorías o subcategorías en un árbol binario.   
Y en el caso de MergeSort:   
La lectura de las transacciones en este caso se realiza en la función visualizarIngresos, donde primero se filtran las transacciones de tipo "ingreso" y se almacenan en un vector llamado ingresos.
Luego, el vector de ingresos es ordenado usando el algoritmo de MergeSort. La función mergeSort es llamada con el vector de transacciones, y divide recursivamente el vector en mitades más pequeñas para luego combinar las mitades de manera ordenada utilizando la función merge.
#### Uso y Funcionamiento del Árbol Binario en el Código
El árbol binario que se utiliza en el código es una estructura de datos para almacenar valores de tipo std::string (en este caso, categorías y subcategorías de las transacciones) de manera ordenada. Este árbol permite realizar operaciones de inserción y recorrido en orden, que son útiles para manejar los datos de forma eficiente.

*Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta* :question:
#### Mi escritura de archivos: 
En términos de escritura de archivos, se está utilizando la clase std::ofstream para generar un reporte anual de gastos e ingresos.   
Primero, necesité una función que filtra los ingresos y los ordena antes de escribirlos en el archivo.
Esto se puede ver mostrado de la 327 - 361
Ahora, el código recorre el vector gastos, que contiene todas las transacciones filtradas y ordenadas, y escribe la información de cada transacción en el archivo.

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








