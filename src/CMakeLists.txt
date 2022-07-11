cmake_minimum_required(VERSION 3.00)
project(TwentyOne VERSION 0.0.1)


set(CMAKE_C_STANDARD 11)

add_library( 
	deck_config
	deck_config.h
	deck_config.c
)
add_subdirectory(types)
add_subdirectory(general_logic)

add_executable(TwentyOne_0_0_1 main.c )


target_link_libraries(TwentyOne_0_0_1 PUBLIC deck_config)
target_link_libraries(TwentyOne_0_0_1 PUBLIC general-logic)
target_link_libraries(TwentyOne_0_0_1 PUBLIC types)