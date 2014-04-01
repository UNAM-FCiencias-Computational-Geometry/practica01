/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 *
 */

#include "double_linked_list/double_linked_list.h"
#include "lines/lines.h"
#include "points/2d_points.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct double_linked_list* init_double_linked_list()
{
	struct double_linked_list* list;
	list = (struct double_linked_list*) malloc(sizeof(struct double_linked_list));
	

	if (list == NULL) {
		printf("Ya no hay memoria disponible: init_double_linked_list()");
		exit(EXIT_FAILURE);
	}

	list->size = 0;
	list->head = list->tail = NULL;

	return list;
}

void destroy_double_linked_list(struct double_linked_list* list)
{
	while(!empty_list(list))
		pop_front(list);
	free(list);
}

void destroy_double_linked_list_with_points(struct double_linked_list* list)
{	
	while (!empty_list(list))
		destroy_point(pop_front(list));
	
	free(list);
}


int empty_list(struct double_linked_list* list)
{
	if (list != NULL) {
		return list->size == 0;
	} else {
	 	return list == NULL;
	}
}
 
struct list_item* init_list_item()
{
	struct list_item* item;
	item = (struct list_item*) malloc(sizeof(struct list_item));
	
	if (item == NULL) {
		printf("Ya no hay memoria disponible: init_list_item()");
		exit(EXIT_FAILURE);
	}

	item->point = NULL;
	item->left = NULL;
	item->right = NULL;
	
	return item;
}

void destroy_list_item(struct list_item* item)
{
	free(item);
}

struct double_linked_list* create_copy_list(struct double_linked_list* list)
{
	struct double_linked_list* copy;
	copy = init_double_linked_list();
	
	struct list_item* tmp;
	tmp = list->head;
	
	while(tmp != NULL) {
		push_back(copy, tmp->point);
		tmp = tmp->right;
	}

	return copy;
}

void push_back(struct double_linked_list* list,  struct point* point)
{
	struct list_item *tmp1, *tmp2;

	tmp2 = init_list_item();
	tmp2->point = point;

	
	if (empty_list(list)) {
		list->head = list->tail = tmp2;
		list->size += 1;
		return;
	}
	
	tmp1 = list->tail;
	tmp1->right = tmp2;
	
	tmp2->left = tmp1;
  	list->tail = tmp2;
	list->size += 1;
	return;
}

void push_front(struct double_linked_list* list, struct point* point)
{
	struct list_item *tmp1, *tmp2;

	tmp2 = init_list_item();

	tmp2->point = point;

	
	if (empty_list(list)) {
		list->head = list->tail = tmp2;
		list->size += 1;
		return;
	}
	
	tmp1 = list->head;
	tmp1->left = tmp2;
	
	tmp2->right = tmp1;
	list->head = tmp2;

	list->size += 1;
	return;
}

struct point* pop_back(struct double_linked_list* list)
{
	
	if (empty_list(list))
		return NULL;

	struct list_item *tmp1, *tmp2;
	tmp1 = list->tail;
	tmp2 = tmp1->left;
	
 	struct point* point;
	
	list->size -= 1;
	if (list->size == 0) {
		list->head = list->tail = NULL;
	} else {
		tmp2->right = NULL;
		list->tail = tmp2;
	}
	
	point = tmp1->point;
	destroy_list_item(tmp1);
	
	return point;
}

struct point* pop_front(struct double_linked_list* list)
{
	if (empty_list(list)) 
		return NULL;

	struct list_item *tmp1, *tmp2;
	tmp1 = list->head;	
	tmp2 = tmp1->right;
	
	struct point* point;
	
	list->size -= 1;
	if (list->size == 0) {
		list->head = list->tail = NULL;
	} else {
		tmp2->left = NULL;
		list->head = tmp2;
	}

	point = tmp1->point;

	destroy_list_item(tmp1);
	return point;
}

struct point* pick_back(struct double_linked_list* list)
{
	if (empty_list(list))
		return NULL;
	else
		return list->tail->point;
}

struct point* pick_front(struct double_linked_list* list)
{
	if (empty_list(list))
		return NULL;
	else
		return list->head->point;
}

struct point* right_point(struct double_linked_list* list){
	
	if(empty_list(list))
		return NULL;
		
	struct double_linked_list* lista_aux = init_double_linked_list();
	struct list_item* tmp = list->head;
	struct point* right = tmp->point;
	tmp = tmp->right;
	
	while(tmp != NULL){
		if(menor(tmp->point,right)){
			push_back(lista_aux, tmp->point);
			tmp = tmp->right;
		}else{
			push_back(lista_aux,right);
			right = tmp->point;
			tmp = tmp->right;
		}
	}
	
	*list = *lista_aux;
	free(lista_aux);
	return right;	
}
 
struct point* left_point(struct double_linked_list* list){
	
	if(empty_list(list))
		return NULL;
	
	struct double_linked_list* lista_aux = init_double_linked_list();
	struct list_item* tmp = list->head;
	struct point* left = tmp->point;
	tmp = tmp->right;
	
	while(tmp != NULL){
		if(menor(left,tmp->point)){
			push_back(lista_aux, tmp->point);
			tmp = tmp->right;
		}else{
			push_back(lista_aux, left);
			left = tmp->point;
			tmp = tmp->right;
		}
	}
		
	*list = *lista_aux;
	free(lista_aux);
	return left;	
}

void print_list(struct double_linked_list* list){
	if(empty_list(list)){
		printf("[]\n");
	}else{
		struct list_item* tmp = list->head;
		printf("[");
		while(tmp != NULL){
			if(tmp -> right == NULL){
				printf("(%d,%d)", tmp->point->x,tmp->point->y);
				tmp = tmp -> right;
			}else{
				printf("(%d,%d),", tmp->point->x,tmp->point->y);
				tmp = tmp -> right;
			}
		}
		printf("]\n");
	}
} 	

struct point* max_distance(struct point* p1, struct point* p2, struct double_linked_list* list){
	if(empty_list(list))
		return NULL;
	
	struct double_linked_list* list_aux = init_double_linked_list();
	struct list_item* tmp = list->head;
	struct point* max;
	struct line* line_tmp = init_line_points(p1,p2);
	
	max = tmp->point;
	float distancia_max, distancia_tmp;
	distancia_max = distance_point_to_line(line_tmp, max);
	tmp = tmp->right;	
	
	while(tmp != NULL){
		distancia_tmp = distance_point_to_line(line_tmp, tmp->point);
		if(distancia_tmp > distancia_max){
			distancia_max = distancia_tmp;
			push_back(list_aux,max);
			max = tmp->point;
			tmp = tmp->right;
		}else{
			push_back(list_aux,tmp->point);
			tmp = tmp->right;
		}
	}
	
	*list = *list_aux;			
	free(list_aux);
	return max;
}

struct double_linked_list* points_strictly_right(struct point* p1, struct point* p2, struct double_linked_list* list){
	
	struct double_linked_list *l, *l_aux;
	l = init_double_linked_list();
	l_aux = init_double_linked_list();
	
	struct list_item* tmp = list->head;

	while(tmp != NULL){
		if(curve_orientation(p1, tmp->point, p2) == 0){
			push_back(l,tmp->point);
			tmp = tmp->right;
		}else{
			push_back(l_aux,tmp->point);
			tmp = tmp->right;
		}
	}
	
	*list = *l_aux;
	free(l_aux);
	
	return l;
}

struct double_linked_list* append_list(struct double_linked_list* l1, struct double_linked_list* l2){
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;
	
	struct double_linked_list* l = create_copy_list(l1);
	struct list_item* tmp= l2->head;
	
	while(tmp != NULL){
		push_back(l,tmp->point);
		tmp = tmp->right;
	}
	return l;	
}

