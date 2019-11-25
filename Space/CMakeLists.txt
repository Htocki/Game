cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (Space)

if (MSVC) 
	set (SFML_DIR "SFML-2.5.1/lib/cmake/SFML")
endif ()

find_package (SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

include_directories (Include)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED on)

add_executable (${PROJECT_NAME}
	Main.cpp
	Source/Graphics/Widget.cpp
    Source/Graphics/Label.cpp
	Source/Game.cpp
	Source/Player.cpp 
	Source/Spaceship.cpp
	Source/Statistic.cpp
	Source/GameObject.cpp
	Source/RandomizedMatrix.cpp
	Source/Tilemap.cpp
	)


target_link_libraries (${PROJECT_NAME} 
	sfml-graphics 
	sfml-window 
	sfml-system 
	sfml-audio 
	sfml-network
	)

if (MSVC)
	set_property(TARGET ${PROJECT_NAME} APPEND_STRING
		PROPERTY LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
	)
endif ()