# -*- coding: utf-8 -*-
# 
# Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
#
require 'ffi'

require File.expand_path(File.join(File.dirname(__FILE__), "points"))

#
# Modulo para mapear la lista doblemente ligada y sus funciones de C a Ruby
#
module List
  extend FFI::Library
  ffi_lib "lib/libdouble_linked_list.so"

  class Item < FFI::Struct
    layout :left, :pointer,
           :right, :pointer,
           :point, :pointer
    end

  class List < FFI::Struct
    layout :head, :pointer,
           :tail, :pointer
  end

  attach_function :init_double_linked_list, [], List.by_ref
  attach_function :destroy_double_linked_list, [List.by_ref], :void
  attach_function :destroy_double_linked_list_with_points, [List.by_ref], :void
  
  attach_function :init_list_item, [], Item.by_ref
  attach_function :destroy_list_item, [Item.by_ref], :void

  attach_function :push_back, [List.by_ref, Points::Point.by_ref], :void
  attach_function :push_front, [List.by_ref, Points::Point.by_ref], :void

  attach_function :pop_back, [List.by_ref], Points::Point.by_ref
  attach_function :pop_front, [List.by_ref], Points::Point.by_ref
  
  attach_function :pick_back, [List.by_ref], Points::Point.by_ref
  attach_function :pick_front, [List.by_ref], Points::Point.by_ref

  # Public: Convierte una lista de C a un arreglo de Ruby.
  # 
  # list - La lista que se quiere convertir a un arreglo.
  # 
  # Examples
  #    
  #     List.to_a((1,2),(2,4)) Recuerda que la entrada es una lista de C.
  #     # => [[1,2],[2,4]]
  #
  # Regresa un arreglo
  def self.to_a(list)
    array = Array.new
    while not(pick_front(list).null?)
      
      array << Points.to_a(pop_front(list))
    end
    array
  end
  
end
