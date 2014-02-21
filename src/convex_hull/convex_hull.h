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

#endif
