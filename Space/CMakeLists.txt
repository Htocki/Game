#sets up the minimum version of cmake
cmake_minimum_required(VERSION 3.9) # personally I'd set this version as low as required; you don't have to require the cutting edge version

#how the project will be called
project (space)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

add_executable(space 
	Main.cpp
	Game.hpp Game.cpp
	Statistic.hpp Statistic.cpp 
	StringHelpers.hpp
	Aircraft.hpp Aircraft.cpp
	ResourceHolder.hpp
	Enums.hpp
	)

target_link_libraries(space sfml-graphics sfml-window sfml-system sfml-audio sfml-network)