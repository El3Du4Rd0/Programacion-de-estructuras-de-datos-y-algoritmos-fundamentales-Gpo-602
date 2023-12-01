# Programacion-de-estructuras-de-datos-y-algoritmos-fundamentales-Gpo-602
Mi programa consta de un asistente de creador de mazos el cual organiza varias cartas de formas diferentes:
por coste de maná, por puntos de vida, por puntos de ataque y por nombre. Además, mi programa tambien permite agregar
nuevas cartas tanto a la estructura de datos como a al archivo txt. 

## Competencias:

### SICT0301 Evalúa los componentes

- Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
- Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.
- Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

Análisis de comlplejidad:
- Caso con variables de tipo int: Heapify & Heapsort O(n log n) cuando tienes que acomodar todo el mosticulo desde la base
- Caso con variables de tipo string: Heapify & Heapsort O(n * m log n * m) donde m son los caracteres que son iguales entre los strings
- Caso con variables de tipo int: Push O(n) ya que tiene un ciclo while
- Caso con variables de tipo string: Push O(n * m) donde m son los caracteres que son iguales entre los strings

### SICT0302 Toma decisiones

- Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
- Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

Yo utilice una estructura de datos de tipo Heap, ya que me permitia mantener un orden al mismo tiempo que se iban agregando datos de distintas formas 
de menor a mayor. Ademas, el metodo para adicionar datos tiene una complejidad de O(n)

### SICT0303 Implementa acciones científicas

- Implementa mecanismos para consultar información de las estructras correctos.
- Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta.

En mi archivo main utilizo un archivo txt para cargar todos los datos que necesito para mi estructura de datos de tipo heap. Ademas, cuando agrego datos
los datos nuevos se escriben con el formato correcto directo en el archivo txt para luego poder ser consultados en un futuro. Los datos de mi estructura los consulto al ir extrallendo el valor top de mi heap uno por uno. 

## Consideraciones:
Mi proyecto esta hecho completamente con C++ estandar
