# -*- coding: utf-8 -*-
#
# Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
#

# Public: Inicializa la ventana y variables de processing
#
def setup
  background 255, 255, 255
  size(450, 450,P2D)
  # Conjunto de puntos prueba.
  @points = [[10,8],[1,3],[5,9], [1,1] , [7,5],[9,5],[8,1]]
  
  @points = @points.map do |x|
    [x[0]*35,x[1]*35]
  end
  draw_convex_hull
end

# Public: Dibuja el poligono convexo del conjunto de puntos @points
#
# Esta funcion la debes de modificar para que dibuje los puntos
def draw_convex_hull
  @points.each do
    |point|
    ellipse(point[0].to_f, point[1].to_f,5.0,5.0)
  end
  
  # Arreglo que representa el poligono convexo de @points
  convex_hull = construct_convex_hull(@points)

  #
  # Aqui van tu codigo que dibuje el poligono convexo
  #
  
end


# Public: Calcula el cierre convexo de un arreglo de puntos
def construct_convex_hull(points)
  require File.expand_path(File.join(File.dirname(__FILE__), "../shared_libraries/convex_hull"))
  
  list = List.init_double_linked_list
  @points.each do |point|
    List.push_front(list,Points.init_point(point[0],point[1]))
  end 
  
  convex = ConvexHull.convex_hull(list)
  
  convex_set = List.to_a(convex)
  
  List.destroy_double_linked_list(convex)
  List.destroy_double_linked_list_with_points(list)

  return convex_set  
end
