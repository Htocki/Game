cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (PROJECT Game)

set (HEADERS
	../includes/Graphics/Label.hpp
	../includes/Graphics/Widget.hpp
	../includes/Utility/Generator.hpp
	../includes/Utility/ToString.hpp
	../includes/Utility/ToString.inl
	../includes/Enums.hpp
	../includes/Game.hpp
	../includes/GameObject.hpp
	../includes/Player.hpp
	../includes/RandomizedMatrix.hpp
	../includes/ResourceHolder.hpp
	../includes/ResourceHolder.inl
	../includes/Spaceship.hpp
	../includes/Statistic.hpp
	../includes/Tilemap.hpp
	)

set (SOURCES 
	../sources/Graphics/Label.cpp
	../sources/Graphics/Widget.cpp
	../sources/Game.cpp
	../sources/GameObject.cpp
	../sources/Main.cpp
	../sources/Player.cpp
	../sources/RandomizedMatrix.cpp
	../sources/Spaceship.cpp
	../sources/Statistic.cpp
	../sources/Tilemap.cpp
	)

project (${PROJECT})

// Solve the problem of connecting the parent directory.
include_directories (../)

if (MSVC) 
	// Solve the problem of connecting the parent directory. 
	set (SFML_DIR "../libraries/windows/SFML-2.5.1/lib/cmake/SFML")
endif ()

find_package (SFML 2.5.1 COMPONENTS graphics window system audio network REQUIRED)

if (MSVC)
	add_definitions (/W4)
elseif (CMAKE_COMPILER_IS_GNUCXX)
	add_definitions (-Wall -pedantic)
else ()
	message ("Unknown compiler")
endif ()

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_link_libraries (${PROJECT} 
	sfml-graphics 
	sfml-window 
	sfml-system 
	sfml-audio 
	sfml-network
	)

if (MSVC)
	set_property(TARGET ${PROJECT} APPEND_STRING
		PROPERTY LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
		)
endif ()