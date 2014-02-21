# -*- coding: utf-8 -*-
# 
# Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
#
require File.expand_path(File.join(File.dirname(__FILE__), "../shared_libraries/convex_hull"))

#
# Reabre el modulo de Test para agregar la clase TestConvexHull, la cual
# tiene los tests del cierre convexo de C.
# 
module Test
  extend ConvexHull  
  class TestConvexHull

    # Public: Calcula el cierre convexo de un arreglo de Ruby
    # Complexity: O(n^3)
    #
    # points - Una arreglo de arreglos de dos enteros que representan los puntos.
    #
    # Examples
    #
    #    Test::TestConvexHull.convex_hull_test([[0,0],[1,2],[5,7]])
    #    # => [[0,0],[1,2],[5,7]]
    #
    # Regresa el conjunto de puntos que forma parte del cierre convexo
    def self.convex_hull_test(points)
      convex = Array.new
      is_left = true
   
      points.each do
        |i|
        points.each do
          |j|
          if (i != j) then
            points.each do
              |k|
              if (k != i and k != j) then
                if not(self.curve_orientation(i,j,k))
                  is_left = false
                end
              end
            end
            if is_left then
              convex << i
              convex << j
            else
              is_left = true
            end
          end
        end
      end
      convex.uniq
    end

    # Public: Responde si es una vuelta a la derecha o vuelta a la izquierda.
    # 
    # a - Arreglo de dos enteros  
    # b - Arreglo de dos enteros
    # c - Arreglo de dos enteros
    #
    # Examples
    #
    #    Test::TestConvexHull.curve_orientation([[0,0],[0,1].[0,3]])
    #    # => -1
    #
    # Regresa false si es vuelta a la derecha, true si es vuelta a la izquierda
    # y -1 si los puntos son colineales
    def self.curve_orientation(a,b,c)
      right = false
      left = true
      x = 0
      y = 1
      
      det_o = ((b[x] - a[x])*(c[y] - a[y])) - ((c[x] - a[x])*(b[y] - a[y]))      

      if det_o < 0
        return right
      elsif det_o > 0
        return left
      else
        return -1
      end
    end
    
    # Public: Prueba la funcion que calcula el cierre convex de C con un conjunto
    # de puntos vacio.
    #
    # Examples
    #
    #     Test::TestConvexHull.empty_set
    #     # => true
    # 
    # Regresa true si la funcion en C responde de forma correcta o false en caso 
    # contrario.
    def self.empty_set
      list = List.init_double_linked_list
      convex_set = ConvexHull.convex_hull(list)

      result = convex_set.null?

      List.destroy_double_linked_list(list)
      result
    end

    # Public: Prueba la funcion que calcula el cierre convex de C con un conjunto
    # de puntos de cardinalidad 3.
    #
    # Examples
    #
    #     Test::TestConvexHull.three_points
    #     # => true
    # 
    # Regresa true si la funcion en C responde de forma correcta o false en caso 
    # contrario.
    def self.three_points     
      list = List.init_double_linked_list
      3.times.each do 
       |x|
        point = Points.init_point(rand(1000) - 500,rand(1000) - 500)
        List.push_front(list,point)
      end
      
      convex_set = ConvexHull.convex_hull(list)
      
      set_points =  List.to_a(list)
      convex_set_points = List.to_a(convex_set)

      List.destroy_double_linked_list(convex_set)
      List.destroy_double_linked_list_with_points(list)

      result = (set_points.clone & convex_set_points.clone) == set_points.clone
      
      result
    end
    
    # Public: Prueba la funcion que calcula el cierre convex de C de un conjunto de
    # puntos de cardinalidad aleatoria mayor a 3, que no son colineales.
    #
    # Examples
    #
    #     Test::TestConvexHull.random_set_points
    #     # => true
    # 
    # Regresa true si la funcion en C responde de forma correcta o false en caso 
    # contrario.
    def self.random_set_points
      list = List.init_double_linked_list
      
      times = (3 + rand(100)).times

      points = Array.new

      times.each do |x|
        points << [rand(10000)-5000, rand(10000)-5000]
      end

      points.each do |i|
        points.each do |j|
          if (i != j)
            points.each do |k|
              if (k != i and k != j)
                if curve_orientation(i,j,k) == -1 then
                  points.delete(k)
                  points.delete(j)
                  points.delete(i)
                end
              end
            end
          end
        end
      end

      points.each do |point|
        List.push_front(list,Points.init_point(point[0],point[1]))
      end

      convex_set = ConvexHull.convex_hull(list)

      set_points =  List.to_a(list)
      convex_set_test = convex_hull_test(set_points)
      convex_set_points = List.to_a(convex_set)

      List.destroy_double_linked_list(convex_set)
      List.destroy_double_linked_list_with_points(list)

      result = convex_set_test & convex_set_points == convex_set_test
      
      result
    end
  end
end
