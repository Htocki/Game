cmake_minimum_required(VERSION 3.15)

project (space)

set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)


include_directories(include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_executable(space
	Main.cpp
	source/Game.cpp
	source/Statistic.cpp 
	source/Aircraft.cpp
	)


target_link_libraries(space sfml-graphics sfml-window sfml-system sfml-audio sfml-network)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")