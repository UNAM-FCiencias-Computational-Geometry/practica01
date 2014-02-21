# -*- coding: utf-8 -*-
# 
# Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
#

require File.expand_path(File.join(File.dirname(__FILE__), "../shared_libraries/double_linked_list"))

#
# Reabre el modulo de Test para agregar las clases TestPoints y TestList, las cuales
# tiene los test de las funciones de amabas estructuras de C.
#
module Test
  extend List
  
  class TestPoints

    # Public: Prueba la funcion que copia puntos que se le pasen.
    #
    # Examples
    #
    #     Test::TestPoints.create_copy_point
    #     # => true
    # 
    # Regresa true si la funcion en C responde de forma correcta o false en caso 
    # contrario.
    def self.create_copy_point
      x = rand(2**27)
      y = rand(2**27)
      point = Points.init_point(x,y)
      point_copy = Points.create_copy_point(point)

      if not(point_copy.null?)
        result = point[:x] == point_copy[:x] and point[:y] == point_copy[:y]
      else
        result false
      end
        
      Points.destroy_point(point)
      Points.destroy_point(point_copy)
      
      result
    end
  end

  class TestList

    # Public: Prueba las funciones pop_back y pop_front de una lista
    # vacia.
    #
    # Examples
    #
    #     Test::TestList.pop_empty_list
    #     # => true
    # 
    # Regresa true si las funciones en C responden de forma correcta o false en caso 
    # contrario.
    def self.pop_empty_list
      point = Points.init_point_empty
      list = List.init_double_linked_list
      
      result = List.pop_back(list).null? and List.pop_front(list).null?
      
      List.destroy_double_linked_list(list)

      result
    end

    # Public: Prueba las funciones pop_back y pop_front de una lista
    # con elementos, que pasado cierto punto queda vacia.
    #
    # Examples
    #
    #     Test::TestList.more_pop
    #     # => true
    # 
    # Regresa true si las funciones en C responden de forma correcta o false en caso 
    # contrario.
    def self.more_pop
      list = List.init_double_linked_list
      
      items = rand(1000)
      items.times.each do
        |item|
        if ([true,false].sample)
          List.push_front(list,nil)
        else
          point = Points.init_point_empty
          List.push_back(list,point)
        end
      end

      items.times.each do
        |item|
        if ([true,false].sample)
          Points.destroy_point(List.pop_front(list))
        else
          Points.destroy_point(List.pop_back(list))
        end 
      end

      result = List.pop_front(list).null? and List.pop_back(list).null?
      List.destroy_double_linked_list(list)
      
      result
    end   
    
    # Public: Prueba las funciones pop_back y pop_front de una lista
    # con muchos elementos.
    #
    # Examples
    #
    #     Test::TestList.more_push
    #     # => true
    # 
    # Regresa true si las funciones en C responden de forma correcta o false en caso 
    # contrario.
    def self.more_push
      list = List.init_double_linked_list
      
      items = rand(1000)
      pop = rand(items) while pop.nil? or pop <= 1 or pop + 1 == items

      point = Points.init_point(rand(pop),rand(pop))
      items.times.each do
        |item|
        if pop - 1 != item then
            List.push_front(list,nil)
        else
            List.push_front(list,point)
        end          
      end
      
      (items-pop).times.each do
        |item|
        point_copy = List.pop_front(list)
      end

      point_copy = List.pop_front(list)
      
      result = point_copy.pointer == point.pointer ? true : false

      List.destroy_double_linked_list(list)
      list = List.init_double_linked_list
       
      items.times.each do
        |item|
        if pop - 1 != item then
            List.push_back(list,nil)
        else
            List.push_back(list,point)
        end          
      end
      
      (items-pop).times.each do
        |item|
        point_copy = List.pop_back(list)
      end
      point_copy = List.pop_back(list)
      
      result = point_copy.pointer == point.pointer ? result : false

      List.destroy_double_linked_list(list)
      Points.destroy_point(point_copy)
      result
    end
    
    # Public: Prueba las funciones pick_back y pick_front de una lista
    # vacia.
    #
    # Examples
    #
    #     Test::TestList.pick_empty_list
    #     # => true
    # 
    # Regresa true si las funciones en C responden de forma correcta o false en caso 
    # contrario.
    def self.pick_empty_list
      list = List.init_double_linked_list
      
      pick = List.pick_front(list)
      return false if not(pick.null?)
      
      pick = List.pick_back(list)
      return false if not(pick.null?)
      
      return true
    end
    
    # Public: Prueba las funciones pick_back y pick_front de una lista
    # con varios elementos.
    #
    # Examples
    #
    #     Test::TestList.pick
    #     # => true
    # 
    # Regresa true si las funciones en C responden de forma correcta o false en caso 
    # contrario.
    def self.pick
      list = List.init_double_linked_list
      point = Points.init_point(rand(500),rand(500))
      
      times = rand(1000)
      
      times.times.each do 
        |count|
        List.push_front(list,nil)
      end
      List.push_front(list,point)
      
      point_copy = List.pick_front(list)
      result = point_copy.pointer == point.pointer ? true : false

      List.destroy_double_linked_list(list)
      
      list = List.init_double_linked_list
      
      point = Points.init_point(rand(500),rand(500))
      times.times.each do 
        |count|
        List.push_back(list,nil)
      end
      List.push_back(list,point)
      
      point_copy = List.pick_back(list)
      result = point_copy.pointer == point.pointer ? result : false
      
      List.destroy_double_linked_list(list)
      
      result
    end
  end
end
