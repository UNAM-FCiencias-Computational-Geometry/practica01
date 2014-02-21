/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 *
 * Description:
 * Una lista doblemente ligada que sirve como stack y como queue.
 * Sirve para representar un poligono simple o un conjunto de puntos.
 */

#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

#include "points/2d_points.h"

/**
 *  |-----------|   left |-----------|  right |-----------|
 *  |           | <----- | list_item | -----> |           |
 *  |-----------|        |-----------|        |-----------|
 */
struct list_item {
	struct point* point;
	struct list_item* left;
	struct list_item* right;
};

/**
 * |------------|                     |------------|
 * |    head    | ----->  .... <----- |    tail    |
 * |------------|                     |------------|
 */
struct double_linked_list {
	struct list_item* head;
	struct list_item* tail;
	int size;
};


/** Inicializa una lista con sus apuntadores nulos. */
struct double_linked_list* init_double_linked_list(void);
/** 
 * Destruye una lista liberando la memoria de sus elementos, sin liberar la memoria
 * de los puntos.
*/
void destroy_double_linked_list(struct double_linked_list*);
/**  Destruye una lista liberando la memoria de sus elementos y de los puntos. */
void destroy_double_linked_list_with_points(struct double_linked_list*);

/** Inicializa un elemento de la lista. */
struct list_item* init_list_item(void);
/** Destruye solo un elemento de la lista, sin liberar la memoria del punto */
void destroy_list_item(struct list_item*);

/** Hace una copia de la lista dada, sin hacer copia de los puntos. */
struct double_linked_list* create_copy_list(struct double_linked_list*);

/** Indica si la lista que se le pasa esta vacía. */
int empty_list(struct double_linked_list*);

/** Agrega un nuevo punto al frente o hasta el final de la lista. */
void push_back(struct double_linked_list*,struct point*);
void push_front(struct double_linked_list*,struct point*);

/* 
 * Quita un punto al frente o hasta el final de la lista, regresa nulo
 * si la lista esta vacia.
 **/
struct point* pop_back(struct double_linked_list*);
struct point* pop_front(struct double_linked_list*);

/**
 * Regresa el punto que esta al frente o al final de la lista, si es una lista vacia
 * entonces regresa nulo.
 */
struct point* pick_back(struct double_linked_list*);
struct point* pick_front(struct double_linked_list*);

#endif
