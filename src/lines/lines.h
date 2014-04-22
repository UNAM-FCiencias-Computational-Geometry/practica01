#ifndef LINES
#define LINES

#include "points/2d_points.h"

// linea de la forma Ax + By + C = 0
struct line{
	int a;
	int b;
	int c;
};

/** inicializa una linea a partir de dos puntos*/
struct line* init_line_points(struct point*, struct point*);

/** inicializa una linea de la forma general Ax + By + c = 0*/
struct line* init_line(int, int, int);

/** calcula la distancia de un punto a una linea*/
float distance_point_to_line(struct line*, struct point*);

#endif
