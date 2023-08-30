cmake_minimum_required(VERSION 3.15)
project(MatteoAnnunziata_ProgettoLaboratorio)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES Item.cpp Item.h Observer.h ShoppingList.cpp ShoppingList.h Subject.h User.cpp User.h)
add_executable(MatteoAnnunziata_ProgettoLaboratorio main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(MatteoAnnunziata_ProgettoLaboratorio core)