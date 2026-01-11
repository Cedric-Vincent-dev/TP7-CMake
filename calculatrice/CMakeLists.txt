cmake_minimum_required(VERSION 3.10)

project(Calculatrice C)

# Ajout des sous-dossiers contenant des librairies
add_subdirectory(src/lib/staticCalculatrice)
add_subdirectory(src/lib/dynamicCalculatrice)

# Exécutable principal
add_executable(calculatrice src/app/main.c)

# Chemins des headers
target_include_directories(calculatrice PRIVATE
  src/lib/staticCalculatrice
  src/lib/dynamicCalculatrice
)

# Lien avec les librairies
target_link_libraries(calculatrice PRIVATE
  staticCalculatrice
  dynamicCalculatrice
)
