cmake_minimum_required (VERSION 3.15)

project (Space)

## set (SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

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
	Source/Score.cpp
	Source/Spaceship.cpp
	Source/Statistic.cpp
	Source/GameObject.cpp
	)


target_link_libraries (${PROJECT_NAME} 
	sfml-graphics 
	sfml-window 
	sfml-system 
	sfml-audio 
	sfml-network
	)

## set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
