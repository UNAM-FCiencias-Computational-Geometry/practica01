/**
 * Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
 */

#include "convex_hull/convex_hull.h"
#include "double_linked_list/double_linked_list.h"
#include "lines/lines.h"
#include "points/2d_points.h"

#include <stdio.h>
#include <stdlib.h>

struct double_linked_list* convex_hull(struct double_linked_list* set_of_points)
{
	if(empty_list(set_of_points))
		return NULL;
		
	struct point *p_left, *p_right;
	struct double_linked_list *ch_1, *ch_2, *d_points;
	
	p_left = left_point(set_of_points);
	p_right = right_point(set_of_points);
	
	ch_1 = quick_hull_1(p_left, p_right, set_of_points);
	d_points = points_strictly_right(p_left,p_right,set_of_points);
	ch_2 = quick_hull_2(p_left, p_right, d_points);
	push_front(ch_1, p_left);
	push_back(ch_1, p_right);
	
	return append_list(ch_1, ch_2);
}

struct double_linked_list* quick_hull_1(struct point* a, struct point* b, struct double_linked_list* list){
	if(empty_list(list)){
		return NULL;	
	}else{
		struct point* c; //index of point with max distance from ab
		struct double_linked_list *points_strictly_right_A, *points_strictly_right_B, *point_c;
		
		c = max_distance(a,b,list);
		points_strictly_right_A = points_strictly_right(c,a,list);
		points_strictly_right_B = points_strictly_right(b,c,list);
		
		point_c = init_double_linked_list();
		push_back(point_c,c);
		
		return append_list(append_list(quick_hull_1(a,c,points_strictly_right_A),point_c), quick_hull_1			(c,b,points_strictly_right_B)); 
	}
}

struct double_linked_list* quick_hull_2(struct point* a, struct point* b, struct double_linked_list* list){
	if(empty_list(list)){
		return NULL;	
	}else{
		struct point* c; 
		struct double_linked_list *points_strictly_right_A, *points_strictly_right_B, *point_c;
		
		c = max_distance(a,b,list); //index of point with max distance from ab
		points_strictly_right_A = points_strictly_right(c,b,list);
		points_strictly_right_B = points_strictly_right(a,c,list);
		
		point_c = init_double_linked_list();
		push_back(point_c,c);
		
		return append_list(append_list(quick_hull_2(a,c,points_strictly_right_A),point_c), quick_hull_2			(c,b,points_strictly_right_B)); 
	}
}
