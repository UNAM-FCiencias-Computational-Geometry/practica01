/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 */

#include "convex_hull/convex_hull.h"

#include <stdio.h>
#include <stdlib.h>

int lenght_list_item(struct list_item* list){
	int n = 0;
	struct list_item* tmp = list;
	while(tmp != NULL){
		n++;
		tmp = tmp->right;
	}

	return n;
}


int adentro(struct double_linked_list* set_of_points,struct point* point){

	struct list_item* iterador = set_of_points->head;
	struct point* point_i;
	struct point* point_r;
	int n;
	int c;

	for(n = 1;n<(set_of_points->size);n++){
		point_i = iterador->point;
		point_r = iterador->right->point;
		c = curve_orientation(point_i,point_r,point);
		if(c == LEFT){
			return 0;
		}
		iterador = iterador->right;
	}
	point_i = set_of_points->tail->point;
	point_r = set_of_points->head->point;

	c = curve_orientation(point_i,point_r,point);
	return c;
	

}

struct list_item* puente_superior(struct double_linked_list* set_of_points, struct point* point){
	
	struct list_item* iterador = set_of_points->head;
	
	int size = set_of_points->size;
	int resultado1;
	int resultado2;

	struct point* central_point;
	struct point* pointl;
	struct point* pointr;
	int n;

	central_point =iterador->point;
	pointl = set_of_points->tail->point;
	pointr = iterador->right->point;

	resultado1 = curve_orientation(point,central_point,pointl);
	resultado2 = curve_orientation(point,central_point,pointr);

	
	
	if(((resultado1==RIGHT) && (resultado2==RIGHT))||((resultado1==LEFT) && (resultado2==LEFT))){
		
		return iterador;
	}
	
	for(n=1;n<size;n++){
		iterador = iterador->right;
		

		
		central_point = iterador->point;
		pointl = iterador->left->point;
		pointr = iterador->right->point;

		resultado1 = curve_orientation(point,central_point,pointl);
		resultado2 = curve_orientation(point,central_point,pointr);

		if((resultado1==RIGHT && resultado2==RIGHT)||(resultado1==LEFT && resultado2==LEFT)){

		return iterador;
		}
		
	}

	iterador = set_of_points->tail;

	return iterador;
		
}

struct list_item* puente_inferior(struct double_linked_list* set_of_points, struct point* point){
	
	struct list_item* iterador = set_of_points->tail;
	
	int size = set_of_points->size;
	int resultado1;
	int resultado2;

	struct point* central_point;
	struct point* pointl;
	struct point* pointr;
	int n;



	central_point =iterador->point;
	pointl = iterador->left->point;
	pointr = set_of_points->head->point;

	resultado1 = curve_orientation(point,central_point,pointl);
	resultado2 = curve_orientation(point,central_point,pointr);

	
	if(((resultado1==RIGHT) && (resultado2==RIGHT))||((resultado1==LEFT) && (resultado2==LEFT))){
		
		return iterador;
	}
	
	for(n=1;n<size;n++){
		iterador = iterador->left;
		
		central_point = iterador->point;
		pointl = iterador->left->point;
		pointr = iterador->right->point;

		resultado1 = curve_orientation(point,central_point,pointl);
		resultado2 = curve_orientation(point,central_point,pointr);

		if((resultado1==RIGHT && resultado2==RIGHT)||(resultado1==LEFT && resultado2==LEFT)){

		return iterador;
		}
		
	}

	iterador = set_of_points->head;

	return iterador;
		
}

void insertion(struct double_linked_list* set_of_points,struct point* point_insertion){

	int a = adentro(set_of_points,point_insertion);

	if(a == 0){
		struct list_item* ps = puente_superior(set_of_points,point_insertion);
		struct list_item* pi = puente_inferior(set_of_points,point_insertion);
		
		if(ps == set_of_points->head){
			struct point* point1 = ps->point;
			struct point* point2 = ps->right->point;
			int c = curve_orientation(point2,point1,point_insertion);
			if(c ==LEFT){
				struct list_item* aux_tail = set_of_points->tail;
				struct list_item* new_element = init_list_item();
				new_element->point = point_insertion;
				new_element->right = ps;
				ps->left = new_element;
				set_of_points->head = new_element;
				set_of_points->size += 1;
				set_of_points->tail = pi;
				struct list_item* delete_tail = pi->right;
			
			
			
			

				if(delete_tail != NULL){
					pi->right->left = NULL;
					pi->right = NULL;
					int l = lenght_list_item(delete_tail);
					
					set_of_points->size -= l;
				
					struct double_linked_list* list_delete = init_double_linked_list();
					list_delete->head = delete_tail;
					
					list_delete->size = l;
					destroy_double_linked_list_with_points(list_delete);
				}
			}else{
				if(ps->right == pi){
					struct list_item* new_element = init_list_item();
					new_element->point = point_insertion;
					new_element->left = ps;
					new_element->right = pi;
					ps->right = new_element;
					pi->left = new_element;
					set_of_points->size +=1;

				}else{
					
					struct list_item* delete_head = ps->right;
					struct list_item* new_element = init_list_item();

					struct list_item* aux = pi->left;
					aux->right = NULL;
					
					new_element->point= point_insertion;
					new_element->left = ps;
					new_element->right =pi;
					ps->right = new_element;
					delete_head->left = NULL;

					pi->left = new_element;
					
					
					set_of_points->size += 1;
					int l = lenght_list_item(delete_head);
					struct double_linked_list* list_delete_head = init_double_linked_list(); 
					list_delete_head->head = delete_head;
					
					list_delete_head->size=l;
					destroy_double_linked_list_with_points(list_delete_head);
					set_of_points->size -= l;
					
					
				}
			}
			
		}else{
			
			struct point* point_ps = ps->point;
			struct point* point_pi = pi->point;
			struct point* point_head= set_of_points->head->point;

			int c1 = curve_orientation(point_insertion,point_ps,point_head);
			int c2 = curve_orientation(point_ps,point_pi,point_head);
			int c3 = curve_orientation(point_pi,point_insertion,point_head);

			if(c1 == RIGHT && c2 == RIGHT && c3 == RIGHT){

				struct list_item* delete_head = set_of_points->head;
				struct list_item* aux_tail1 =ps->left;
				struct list_item* aux_tail2 =set_of_points->tail;
 
				struct list_item* delete_tail = pi->right;
				struct list_item* new_element = init_list_item();
				
				new_element->point = point_insertion;
				new_element->right = ps;

				ps->left->right = NULL;
				ps->left = new_element;

				set_of_points->head = new_element;
				set_of_points->size += 1;

				int l1 = lenght_list_item(delete_head);
				set_of_points->size -= l1;

				struct double_linked_list* list_delete_head = init_double_linked_list();
				list_delete_head->head = delete_head;
				
				list_delete_head->size = l1;
				destroy_double_linked_list_with_points(list_delete_head);

				set_of_points->tail = pi;
				pi->right = NULL;

				if(delete_tail != NULL){
					int l2 = lenght_list_item(delete_tail);
					delete_tail->left->right = NULL;
					struct double_linked_list* list_delete_tail = init_double_linked_list();
					list_delete_tail->head = delete_tail;
					
					list_delete_tail->size = l2;
					set_of_points->size -= l2;
					destroy_double_linked_list_with_points(list_delete_tail);
				}
				
				
				
			}else{
				if(ps->right == pi){
					struct list_item* new_element = init_list_item();
					new_element->point = point_insertion;
					new_element->left = ps;
					new_element->right = pi;
					ps->right = new_element;
					pi->left = new_element;
					set_of_points->size +=1;

				}else{
					
					struct list_item* delete_head = ps->right;
					struct list_item* new_element = init_list_item();

					struct list_item* aux = pi->left;
					aux->right = NULL;
					
					new_element->point= point_insertion;
					new_element->left = ps;
					new_element->right =pi;
					ps->right = new_element;
					delete_head->left = NULL;

					pi->left = new_element;
					
					
					set_of_points->size += 1;
					int l = lenght_list_item(delete_head);
					struct double_linked_list* list_delete_head = init_double_linked_list(); 
					list_delete_head->head = delete_head;
					
					list_delete_head->size=l;
					destroy_double_linked_list_with_points(list_delete_head);
					set_of_points->size -= l;
					
					
				}
			}
		}
		

	}
}



void imprime_lista(struct double_linked_list* set_of_points){
	struct list_item* lista = set_of_points->head;
	int n;
	int x;
	int y;
	int size = set_of_points->size; 
	for(n = 0;n<size;n++){
		x = lista->point->x;
		y = lista->point->y;
		printf("El valor de (x%i,y%i) es: (%i,%i)\n",n,n,x,y);
		
		lista = lista->right;
		
	}

}

void fix_ch(struct double_linked_list* ch){
	
	struct point* p1 = pop_front(ch);
	struct point* p2 = pop_front(ch);
	struct point* p3 = pop_front(ch);

	int c = curve_orientation(p1,p2,p3);
	if(c==LEFT){
		push_back(ch,p3);
		push_back(ch,p2);
		push_back(ch,p1);
	}else{
		push_back(ch,p1);
		push_back(ch,p2);
		push_back(ch,p3);
	}

}

struct double_linked_list* convex_hull(struct double_linked_list* set_of_points){	
	
	if(empty_list(set_of_points)){
		return NULL;
	}else{

		struct double_linked_list* ch = init_double_linked_list();
		struct list_item* iterador = set_of_points->head;
		struct point* p1 = iterador->point;
		struct point* np1 = init_point(p1->x,p1->y);
		iterador = iterador->right;
		struct point* p2 = iterador->point;
		struct point* np2 = init_point(p2->x,p2->y);
		iterador = iterador->right;
		struct point* p3 = iterador->point;
		struct point* np3 = init_point(p3->x,p3->y);
		push_back(ch,np1);
		push_back(ch,np2);
		push_back(ch,np3);
		
		if(set_of_points->size == 3){

			return ch;
	
		}else{
			
			
			fix_ch(ch);
			struct point* p;
			
			int n = 3;


			while(n < set_of_points->size){
				iterador = iterador->right;
				p = iterador->point;
				struct point* np =init_point(p->x,p->y);
				
				insertion(ch,np);
				n++;
				
			}

			
			return ch;
		}
	}
	
}


