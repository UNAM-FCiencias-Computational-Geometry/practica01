/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 *
 * Description:
 * Contiene todas las funciones que se necesiten para calcular un cierre convexo
 *
 */

#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

#include "double_linked_list/double_linked_list.h"

/** Recibe un poligono y regresa una lista que representa el cierre convexo
 *  del poligono original. 
 *  El poligono que recibe no debe de modificarse, y el poligono  que regresa debe
 *  ser una lista nueva.
 */
struct double_linked_list* convex_hull(struct double_linked_list*);

/** Recibe una lista de puntos y regresa el punto mas
 *  hacia abajo de todos
 */
struct point* getLowest(struct double_linked_list* set_of_points);


/**
 * Recibe un punto inicial y la lista de puntos del polígono
 * y nos regresa al siguiente punto de esa lista que pertenece
 * al cierre convexo
 */
struct point* getNextPoint(struct point* start, struct double_linked_list* set_of_points);

/**
 * Recibe una lista de puntos y calcula el cierre vonvexo
 * con el algoritmo de jarvis
 */
struct double_linked_list*  get_Convex_Hull_Jarvis_Algorithm(struct double_linked_list* set_of_points);

#endif
