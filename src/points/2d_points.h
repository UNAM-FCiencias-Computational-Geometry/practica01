/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 *
 * Description:
 * Contiene la estructura junto con sus funciones que hacen referencia hacia puntos
 * en 2D.
 */
#ifndef TWOD_POINTS_H_
#define TWOD_POINTS_H_

#define LEFT 0
#define RIGHT 1

#define TRUE 1
#define FALSE 0

struct point {
	int x;
	int y;
};

/** Inicializa un punto con coordenadas (0,0) */
struct point* init_point_empty(void);
/** Inicializa un punto con las coordenadas que se le pasan */
struct point* init_point(int, int);
/** Libera la memoria que guarda al punto */
void destroy_point(struct point*);
/** Crea una copia del punto que se le pase */
struct point* create_copy_point(struct point*);
/*
 * Calcula el siguiente determinante:
 *          | 1 a->x a->y |
 * det(O) = | 1 b->x b->y |
 *	        | 1 c->x c->y |
 *
 * Si det(O) < 0 => Vuelta a la derecha.
 * Si det(O) > 0 => Vuelta a la izquierda.
 * Si det(O) == 0 entonces son puntos colineales.
 */
int curve_orientation(struct point*, struct point*,struct point*);

/* Checa si un punto es menor a otro con respecto a la coordenada x */
int menor(struct point*, struct point*);

/* Calcula la distancia entre dos puntos dados*/
float distancia(struct point*, struct point*);

void print_point(struct point*);
#endif
																						
