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


#include <stdlib.h>
#include <stdio.h>

int main()
{
	struct point *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12, *p13, *p14, *p15, *p16, *p17, *p18, *p19, *p20, *p21, *p22, *p23, *p24, *p25, *p26, *p27, *p28, *p29, *p30, *p31, *p32, *p33;
	
	p1 = init_point(-1,11);
	p2 = init_point(-9,7);
	p3 = init_point(-5,8);
	p4 = init_point(-1,8);	
	p5 = init_point(3,8);	
	p6 = init_point(7,8);
	p7 = init_point(-9,4);
	p8 = init_point(2,6);
	p9 = init_point(5,4);
	p10 = init_point(-11,2);
	p11 = init_point(-9,2);
	p12 = init_point(-5,3);
	p13 = init_point(3,2);
	p14 = init_point(8,3);
	p15 = init_point(9,2);
	p16 = init_point(-12,-2);
	p17 = init_point(-10,-3);
	p18 = init_point(-7,-3);
	p19 = init_point(-9,-6);
	p20 = init_point(-7,-4);
	p21 = init_point(-4,-5);
	p22 = init_point(-5,-6);
	p23 = init_point(-2,-9);
	p24 = init_point(-5,-9);
	p25 = init_point(-1,-11);
	p26 = init_point(5,-9);
	p27 = init_point(4,-6);
	p28 = init_point(2,-6);
	p29 = init_point(3,-4);
	p30 = init_point(7,-4);
	p31 = init_point(11,-2);
	
	struct double_linked_list* lista = init_double_linked_list();
	//struct double_linked_list* lista2 = init_double_linked_list();
	
	push_back(lista, p1);
	push_back(lista, p2);
	push_back(lista, p3);
	push_back(lista, p4);
	push_back(lista, p5);
	push_back(lista, p6);
	push_back(lista, p7);
	push_back(lista, p8);
	push_back(lista, p9);
	push_back(lista, p10);
	push_back(lista, p11);
	push_back(lista, p12);
	push_back(lista, p13);
	push_back(lista, p14);
	push_back(lista, p15);
	push_back(lista, p16);
	push_back(lista, p17);
	push_back(lista, p18);
	push_back(lista, p19);
	push_back(lista, p20);
	push_back(lista, p21);
	push_back(lista, p22);
	push_back(lista, p23);
	push_back(lista, p24);
	push_back(lista, p25);
	push_back(lista, p26);
	push_back(lista, p27);
	push_back(lista, p28);
	push_back(lista, p29);
	push_back(lista, p30);
	push_back(lista, p31);

	printf("lista original: ");
	print_list(lista);
	
	printf("cierre convexo: ");
	struct double_linked_list* convex_h = convex_hull(lista);
	print_list(convex_h);
	

	struct double_linked_list* ch3 = init_double_linked_list();
	push_back(ch3, p1);
	push_back(ch3, p2);
	push_back(ch3, p3);
	
	
	printf("pruebas con 3 puntos\n");
	struct double_linked_list* ch = convex_hull(ch3);
	print_list(ch);

	/*
	struct double_linked_list* l = append_list(lista,lista2);	
	print_list(l);
	struct double_linked_list* l1 = init_double_linked_list();
	struct double_linked_list* l2 = append_list(l1,l);
	print_list(l2);
	struct double_linked_list* l3 = append_list(l,l1);
	print_list(l3);
	struct double_linked_list* l4 = init_double_linked_list();
	struct double_linked_list* l5 = append_list(l1,l4);
	print_list(l5);
	//printf("lista original: ");
	//print_list(lista);
	*/
	
	//printf("-----------------------------------\n");
	//printf("%d\n", curve_orientation(p6,p14,p12));
	/*
	p32 = left_point(lista);
	p33 = right_point(lista);
	//printf("ahora la lista es\n");
	//print_list(lista);
	printf("punto izquierdo: ");
	print_point(p32);
	printf("punto derecho: ");
	print_point(p33);
	
	print_list(lista);
	
	//double dist = distancia(p3,p2);
	//printf("distancia = %.2f\n", dist);
	
	//pruebas con max distance
	//struct point* max = max_distance(p8,p7,lista);
	//printf("punto max: (%d, %d)\n",max->x,max->y);
	//print_list(lista);

	//struct list_item* tmp = lista->head;	
	/*
	while(tmp != NULL){
		printf("%d\n", curve_orientation(p7,tmp->point,p8));
		tmp = tmp->right;
	}
	*/
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
	
	//*/
	
	//struct double_linked_list* l1 = init_double_linked_list();
	/*
	struct double_linked_list* ch;
	/*
	push_back(l1,p1);
	push_back(l1,p2);
	push_back(l1,p3);
	
	print_list(l1);
	*/
	/*
	ch = quick_hull_1(p32,p33,lista);
	printf("--------CONVEX HULL-------------\n");
	print_list(ch);
	/*
	struct double_linked_list* lista_de_abajo = points_strictly_right(p32,p33,lista);
	//print_list(lista_de_abajo);
	//struct double_linked_list* ch1 = quick_hull_1(p33,p32,lista_de_abajo);
	//print_list(lista_de_abajo);
	struct double_linked_list* ch2 = quick_hull_2(p32,p33,lista_de_abajo);
	printf("cierre convexo de abajo\n");
	print_list(ch2);
	/*
	// pruebas para points_strictly_right
	printf("----------points_strictly_right\n");
	struct point *pt1, *pt2;
	pt1 = init_point(2,-4);
	pt2 = init_point(18,6);
	print_list(lista);
	lista = points_strictly_right(pt2,pt1,lista);
	print_list(lista);
	*/
	return EXIT_SUCCESS;
 }
