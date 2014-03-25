/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 */

#include "double_linked_list/double_linked_list.h"
#include "points/2d_points.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct point* init_point_empty()
{
	struct point* point = (struct point*) malloc(sizeof(struct point));

	if (point == NULL) {
		printf("Ya no hay memoria disponible: init_double_linked_list()");
		exit(EXIT_FAILURE);
	}

	point->x = 0;
	point->y = 0;

	return point;
}

struct point* init_point(int x, int y)
{
	struct point* point = (struct point*) malloc(sizeof(struct point));

	if (point == NULL) {
		printf("Ya no hay memoria disponible: init_double_linked_list()");
		exit(EXIT_FAILURE);
	}
	
	point->x = x;
	point->y = y;

	return point;
}

void destroy_point(struct point* point)
{
	if (point != NULL)
		free(point);
}

struct point* create_copy_point(struct point* point)
{
	struct point* new_point = init_point(point->x,point->y);
	
	return new_point;
}

int curve_orientation(struct point* a, struct point* b, struct point* c)
{
	int det_o = (b->x - a->x)*(c->y - a->y) - (c->x - a->x)*(b->y - a->y);
	if (det_o < 0) {
		return RIGHT;
	} else if (det_o > 0) {
		return LEFT;
	} else {
		printf("Puntos en posicion general: ");
		printf("a = (%d,%d), b = (%d,%d), c = (%d,%d)\n",
			   a->x,a->y,b->x,b->y,c->x,c->y);
		exit(EXIT_FAILURE);
	}
}

int menor(struct point* p1, struct point* p2){
	if(p1->x < p2->x){
		return TRUE;
	}else if(p1->x > p2->x){
		return FALSE;
	}else if(p1->y < p2->y){
		return TRUE;
	}else{
		return FALSE;
	}
}

float distancia(struct point* p1, struct point* p2){
	
	return sqrt(pow((float)(p2->x - p1->x), 2.0) + pow((float)(p2->y - p1->y), 2.0));
}

struct double_linked_list* points_strictly_right(struct point* p1, struct point* p2, struct double_linked_list* list){
	
	struct double_linked_list* l = init_double_linked_list();
	struct list_item* tmp = list->head;

	while(tmp != NULL){
		if(curve_orientation(p1, tmp->point, p2) == 0){
			push_back(l,tmp->point);
			tmp = tmp->right;
		}else{
			tmp = tmp->right;
		}
	}
	
	free(list);
	
	return l;
}

void print_point(struct point* p1){
	printf("(%d, %d)\n",p1->x,p1->y);
}
