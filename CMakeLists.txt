cmake_minimum_required(VERSION 3.00)
project(TwentyOne VERSION 0.0.1)

add_library(
	general-logic
	src/general_logic.h
	src/general_logic.c
)
add_library(
	card_t
	src/card_t.h
	src/card_t.c
)
add_library( 
	deck_config
	src/deck_config.h

)
add_executable(TwentyOne_0_0_1 src/main.c )

target_link_libraries(card_t PUBLIC deck_config)
target_link_libraries(general-logic PUBLIC deck_config)
target_link_libraries(general-logic PUBLIC card_t)
target_link_libraries(TwentyOne_0_0_1 PUBLIC deck_config)
target_link_libraries(TwentyOne_0_0_1 PUBLIC general-logic)
target_link_libraries(TwentyOne_0_0_1 PUBLIC card_t)