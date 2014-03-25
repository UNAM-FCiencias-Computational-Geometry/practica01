/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 *
 * Description:
 * Este archivo esta pensado para que pruebes las funciones de forma
 * independiente a los tests en un ambiente totalmente controlado por ti.
 * Para compilar este archivo basta con:
 *      $ ruby Makefile.rb compile_c
 * Para correr el programa compilado:
 *      $ ./main
 *
 */

//#include "algorithms/algorithms.h"
#include "convex_hull/convex_hull.h"
#include "double_linked_list/double_linked_list.h"
#include "lines/lines.h"
#include "points/2d_points.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	struct point *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12, *p13, *p14, *p15;
	
	p1 = init_point(13,2);
	p2 = init_point(1,1);
	p3 = init_point(0,0);
	p4 = init_point(3,2);	
	p5 = init_point(12,1);	
	p6 = init_point(7,7);
	p9 = init_point(4,4);
	p10 = init_point(4,7);
	p11 = init_point(5,8);
	p12 = init_point(6,8);
	p13 = init_point(6,7);
	p14 = init_point(7,8);
	p15 = init_point(8,7);
	
	struct double_linked_list* lista = init_double_linked_list();
	push_back(lista, p1);
	push_back(lista, p2);
	push_back(lista, p3);
	push_back(lista, p4);
	push_back(lista, p5);
	push_back(lista, p6);
	push_back(lista, p9);
	push_back(lista, p10);
	push_back(lista, p11);
	push_back(lista, p12);
	push_back(lista, p13);
	push_back(lista, p14);
	push_back(lista, p15);	
	//printf("lista original: ");
	//print_list(lista);
	
	printf("-----------------------------------\n");
	printf("%d\n", curve_orientation(p6,p14,p12));
	
	
	p8 = right_point(lista);
	//printf("ahora la lista es\n");
	//print_list(lista);
	p7 = left_point(lista);
	printf("punto derecho: (%d, %d)\n",p8->x,p8->y);
	printf("punto izquierdo: (%d, %d)\n",p7->x,p7->y);
	
	print_list(lista);
	
	double dist = distancia(p3,p2);
	printf("distancia = %.2f\n", dist);
	
	//pruebas con max distance
	struct point* max = max_distance(p8,p7,lista);
	printf("punto max: (%d, %d)\n",max->x,max->y);
	print_list(lista);

	struct list_item* tmp = lista->head;	
	
	while(tmp != NULL){
		printf("%d\n", curve_orientation(p7,tmp->point,p8));
		tmp = tmp->right;
	}
	/*
	// puebas con line-
	struct point* q1 = init_point(0,0);
	struct point* q2 = init_point(10,10);
	struct line* my_line = init_line_points(q1,q2);
	printf("la ecuacion de la linea es:-----------------\n");
	print_line(my_line);	
				
	//struct line* l = init_line(-1,5,0);
	struct point* p0 = init_point(0,1);			
	printf("distancia : %.2f\n",distance_point_to_line(my_line,p0));
	*/
	
	struct double_linked_list* l1 = init_double_linked_list();
	struct double_linked_list* ch;
	
	push_back(l1,p1);
	push_back(l1,p2);
	push_back(l1,p3);
	
	print_list(l1);
	
	ch = convex_hull(l1);
	print_list(ch);
					
	return EXIT_SUCCESS;
 }
