Geometría Computacional
Práctica 01 Cierre Convexo
Autor: Gaspar Bautista Miguel Angel
Número de cuenta: 30613413-5

El algoritmo que se programo para obtener el cierre convexo es el de Quick Hull. Que consiste
básicamente en obtener primero el punto más a la izquierda y más a la derecha.
Ya que tenemos esos puntos, vamos a obtener el punto más alejado a la linea que forman los puntos
más a la derecha RP y más a la izquierda LP y se agrega a la lista de puntos que forman el cierre convexo, lo
llamamos P.
Despues, de forma recursiva se calcula el cierre convexo de RP y P pero con los puntos que estan estrictamente a la derecha de RP y P y lo concatenamos con el cierre convexo de P y LP pero con los puntos que están estric-
tamente a la izquierda, por ultimo lo hacemos con un punto que esté debajo de la línea que formaron RP y LP y que esté más alejado de los dos, siguiendo la misma idea de tomarse los puntos que son vuelta a la derecha.  

Las estructuras adicionales que se agregaron son:

"lines/lines.h" donde se declara la estructura line que sirve para representar una linea
de la forma Ax + By + C = 0

en el mismo archivo se agregan las funciones que inicializan una línea a partir de dos puntos
init_line_points() donde se utiliza la fórmula ya conocida de geometría analítica, tambien se
se agrega la función init_line(), donde se inicializa una línea con los parametros A,B y C res-
pectivamente. La otra función que agregue es la de distance_point_to_line() donde, como su 
nombre lo dice, calcula la distancia de un punto a una linea, esa funcion es utilizada para deter-
minar que punto es el más alejado.
 
En el archivo que contiene la definicion de los puntos se agregaron las funciones de distancia()
que calcula la distancia entre dos puntos y print_point() que imprime en consola el valor de cada
punto.

En el archivo que contienen las definicion de las listas doblemente ligadas se agregaron las funciones:
right_point(): Regresa el punto más a la  derecha de una lista de puntos, sacandolo de la lista original
left_point(): Regresa el punto más a la izquierda de una lista de puntos, sacandolo de la lista original
print_list():  Imprime una lista de puntos
max_distance(): Regresa el punto más alejado de la recta que se forma dados dos puntos de una lista de puntos y 
lo saca de la lista 
points_strictly_right(): Regresa una lista de puntos que son vuelta a la derecha  con los puntos auxiliares que recibe la función
append_list(): concatena dos listas

En el archivo "convex_hull/convex_hull.h" viene la definición del algoritmo quick hull descrito al principio
pero este lo hace para los puntos que estan arriba y otra funcion de los para los puntos que estan abajo de la 
línea que forman LP y RP descritos tambien al principio.
