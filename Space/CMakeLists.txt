cmake_minimum_required (VERSION 3.15)

project (Space)

set (SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

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


## // Костыль для отключения консольного окна в Windows
## // Добваляется в main.cpp
## #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")