cmake_minimum_required (VERSION 3.15)

set (HEADERS
	"include/Label.h"
	"include/Tilemap.h"
	"include/Widget.h"
	)

set (SOURCES
	"src/Label.cpp"
	"src/Tilemap.cpp"
	"src/Widget.cpp"
)

project ("view")

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

target_include_directories(${PROJECT_NAME}
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
		model
		utility
	)

add_subdirectory ("test")