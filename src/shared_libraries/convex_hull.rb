# -*- coding: utf-8 -*-
#
# Author: José Emiliano Cabrera Blancas (jemiliano.cabrera@gmail.com)
#

require 'ffi'

require File.expand_path(File.join(File.dirname(__FILE__),"double_linked_list"))

#
# Modulo para mapear la funcion de convex_hull escrita en C a Ruby.
#
module ConvexHull
  extend FFI::Library
  ffi_lib "lib/libconvex_hull.so"

  attach_function :convex_hull, [List::List.by_ref], List::List.by_ref 

end
