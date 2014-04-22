#include "lines/lines.h"
#include "points/2d_points.h"	

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct line* init_line_points(struct point* p1, struct point* p2){
	
	struct line* l = (struct line*) malloc(sizeof(struct line));
	
	if (l == NULL){
		printf("Ya no hay memoria disponible: init_line_points()\n");
		exit(EXIT_FAILURE);
	}		
	
	l->a = p2->y - p1->y;
	l->b = -1 * (p2->x - p1->x);
	l->c = (l->a * p1->y) - (l->b * p1->y);

	return l;
}

struct line* init_line(int a, int b, int c){
	struct line* line = (struct line*) malloc(sizeof(struct line));
	
	if(line == NULL){
		printf("Ya no hay memoria disponible: init_line\n");
		exit(EXIT_FAILURE);
	}
	
	line->a = a;
	line->b = b;
	line->c = c;
	
	return line;
}

float distance_point_to_line(struct line* l1, struct point* p1){
	return abs((l1->a * p1->x) + (l1->b * p1->y) + l1->c)/sqrt(pow(l1->a,2.0) + pow(l1->b,2.0));
}

