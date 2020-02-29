cmake_minimum_required (VERSION 3.15)

set (HEADERS
	"include/Assets.h"
	"include/Model.h"
	"include/Player.h"
	)

set (SOURCES
	"src/Assets.cpp"
	"src/Model.cpp"
	"src/Player.cpp"
)

project ("model")

add_library (${PROJECT_NAME}
	STATIC
		${INCLUDE}
		${SOURCES}
    )

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)

target_include_directories (${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
	)

target_link_libraries (${PROJECT_NAME} 
	PUBLIC
		sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
		utility
	)

add_subdirectory ("test")