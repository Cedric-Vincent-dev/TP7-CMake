add_library(dynamicCalculatrice SHARED
  dynamic_calculatrice.c

)

target_include_directories(dynamicCalculatrice PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
