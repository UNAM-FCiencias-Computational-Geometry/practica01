/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 */

#include "convex_hull/convex_hull.h"
#include "points/2d_points.h"

#include <stdio.h>
#include <stdlib.h>

struct double_linked_list* convex_hull(struct double_linked_list* set_of_points)
{
	return get_Convex_Hull_Jarvis_Algorithm(set_of_points);
	
}

struct double_linked_list*  get_Convex_Hull_Jarvis_Algorithm(struct double_linked_list* set_of_points){
	if(set_of_points!=NULL){
		if(!empty_list(set_of_points)){
			struct double_linked_list* points = create_copy_list(set_of_points);
			struct point* lowest=getLowest(points);
			struct point* p=lowest;
			struct double_linked_list* convexHull=init_double_linked_list();
			printf("El más bajo es: (%i,%i)\n",p->x,p->y);
			push_front(convexHull,lowest);
			do{
				p=getNextPoint(p,points);
				if(p!=NULL)
					//printf("P es: (%i,%i)\n",p->x,p->y);
					push_front(convexHull,p);
			}while(p!=lowest);
			destroy_double_linked_list(points);
			return convexHull;
		}
	} 
	return NULL;
}


struct point* getNextPoint(struct point* start, struct double_linked_list* set_of_points){
	struct double_linked_list* list = create_copy_list(set_of_points);
	struct point* p, *q;
	if(!empty_list(list)){
		p=pop_front(list);
		if(p==start && !empty_list(list)){
			//printf("Start=inicio\n");
			p=pop_front(list);
		}
		//printf("Inicio es: (%i,%i)\n",p->x,p->y);
	}
	while (!empty_list(list)){
		q=pop_front(list);
		while((q==p || q==start) && !empty_list(list)){
			//printf("p=q\n");
			q=pop_front(list);
		}
		//printf("Q es: (%i,%i)\n",q->x,q->y);
		if(start != q){
			if(curve_orientation(start,p,q)==RIGHT){
				p=q;
			}
		}
	}
	destroy_double_linked_list(list);
	if(p!= NULL){
		printf("Un punto del cierre es: (%i,%i)\n",p->x,p->y);
		
		return p;
	}
	//printf("Se regresará NULL\n");
	return NULL;
}


struct point* getLowest(struct double_linked_list* set_of_points){
	struct point* p;
	struct point* q;
	struct double_linked_list* points =create_copy_list(set_of_points);
	int i=1;
	while(!empty_list(points)){
		q=pop_front(points);
		//printf("Punto %i: (%i,%i)\n",i,q->x,q->y);
		if(p->y > q->y || p==NULL)
			p=q;
		i++;
	}
	//printf("El menor es: (%i,%i)\n",p->x, p->y);
	destroy_double_linked_list(points);
	return p;
}

