add_library(staticCalculatrice STATIC
  static_calculatrice.c

)

target_include_directories(staticCalculatrice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
