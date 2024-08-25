# Planetas
Examen de Ingreso
Informe de Desarrollo del Código en C para Predicción del Clima en el Sistema Solar
1. Introducción
El problema consiste en predecir las condiciones climáticas de un sistema solar compuesto por tres planetas: Ferengi, Betasoide y Vulcano. Cada planeta se mueve en una órbita circular alrededor del sol con diferentes velocidades angulares y en distintos sentidos (horario y antihorario). La predicción se debe realizar para los próximos 10 años, y el objetivo es determinar:
- La cantidad de períodos de sequía.
- La cantidad de períodos de lluvia y el día del pico máximo de lluvia.
- La cantidad de períodos de condiciones óptimas de presión y temperatura.
2. Premisas del Problema
Premisas del problema:
- Ferengi: Velocidad angular de 1 grado/día en sentido horario. Distancia al sol: 500 km.
- Betasoide: Velocidad angular de 3 grados/día en sentido horario. Distancia al sol: 2000 km.
- Vulcano: Velocidad angular de 5 grados/día en sentido antihorario. Distancia al sol: 1000 km.
- Las órbitas de los planetas son circulares.

Las condiciones climáticas dependen de la alineación de los planetas:
- Sequía: Los tres planetas están alineados entre sí y con el sol.
- Lluvia: Los planetas forman un triángulo que contiene al sol. El pico máximo de lluvia ocurre cuando el perímetro del triángulo es máximo.
- Condiciones Óptimas: Los planetas están alineados entre sí, pero no con el sol.
3. Razonamiento y Solución
Para resolver este problema en C, se debe realizar el cálculo de las posiciones de los planetas día a día durante 10 años (equivalentes a 3650 días). Los cálculos trigonométricos se utilizarán para determinar la posición de cada planeta en su respectiva órbita y evaluar las condiciones climáticas.

1. Posición de los planetas:
   - Se calculará la posición de cada planeta usando las fórmulas trigonométricas en base a su ángulo con respecto al sol.

2. Verificación de alineación:
   - Para determinar si los planetas están alineados, se verificará si las pendientes entre los planetas son iguales.

3. Verificación de inclusión del sol en el triángulo:
   - Para verificar si el sol está dentro del triángulo formado por los planetas, se usarán técnicas de geometría computacional.

4. Cálculo del perímetro del triángulo:
   - Se calculará el perímetro del triángulo formado por los tres planetas y se determinará el día con el perímetro máximo para identificar el pico de lluvia.
4. Código Desarrollado en C
En el archivo ¨Planetas.c¨ se encuentra el código desarrollado en C para resolver el problema.
5. Conclusión
El programa desarrollado en C permite predecir los períodos de sequía, lluvia y condiciones óptimas en un sistema solar ficticio. Utilizando técnicas de geometría y trigonometría, el programa simula el comportamiento de los planetas durante 10 años y determina las condiciones climáticas en función de sus posiciones relativas. Además, se identifica el día en que ocurre el pico máximo de lluvia.
