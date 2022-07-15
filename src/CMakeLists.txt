cmake_minimum_required(VERSION 3.00)
project(Ccards VERSION 0.0.3)


set(CMAKE_C_STANDARD 11)

add_library( 
	deck_config
	deck_config.h
	deck_config.c
)
add_subdirectory(types)
add_subdirectory(general_logic)
add_subdirectory(ccard_ai)

add_executable(Ccards main.c )


target_link_libraries(Ccards PUBLIC deck_config)
target_link_libraries(Ccards PUBLIC general-logic)
target_link_libraries(Ccards PUBLIC types)
target_link_libraries(Ccards PUBLIC ccard_ai)