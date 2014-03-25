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
	//return NULL;

	if(empty_list(set_of_points)){
		return NULL;
	}
	
	//print_list(set_of_points);
	//struct double_linked_list* l_aux = create_copy_list(set_of_points);
	struct double_linked_list* convex_h = init_double_linked_list();
	struct point *left, *right, *piv; 
	
	left = left_point(set_of_points);
	right = right_point(set_of_points);
	printf("flag\n");
	piv = max_distance(left,right,set_of_points);
	
	push_back(convex_h, left);
	push_back(convex_h, right);
	push_back(convex_h, piv);	
		
	return convex_h;

}
