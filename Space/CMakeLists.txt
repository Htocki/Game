cmake_minimum_required(VERSION 3.15)

project (space)

set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")



find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

add_executable(space
	Main.cpp
	Game.cpp
	Statistic.cpp 
	Aircraft.cpp
	)

target_link_libraries(space sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")