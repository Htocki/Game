cmake_minimum_required (VERSION 3.15)

set(HEADERS
	"include/Graphics/Label.hpp"
	"include/Graphics/Widget.hpp"
	"include/Utility/Generator.hpp"
	"include/Utility/ToString.hpp"
	"include/Enums.hpp"
	"include/Game.hpp"
	"include/GameObject.hpp"
	"include/Player.hpp"
	"include/RandomizedMatrix.hpp"
	"include/ResourceHolder.hpp"
	"include/Spaceship.hpp"
	"include/Statistic.hpp"
	"include/Tilemap.hpp"
	)

set(SOURCES 
	"src/Graphics/Label.cpp"
	"src/Graphics/Widget.cpp"
	"src/Game.cpp"
	"src/GameObject.cpp"
	"src/Main.cpp"
	"src/Player.cpp"
	"src/RandomizedMatrix.cpp"
	"src/Spaceship.cpp"
	"src/Statistic.cpp"
	"src/Tilemap.cpp"
	)

project("game")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME}
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

if(MSVC)
	add_definitions(/W4)
elseif (CMAKE_COMPILER_IS_GNUCXX)
	add_definitions(-Wall -pedantic)
else()
	message ("Unknown compiler")
endif()

if (MSVC)
	set_property(TARGET ${PROJECT_NAME} APPEND_STRING
		PROPERTY LINK_FLAGS 
			"/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
	)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

#include extern libs
include(FetchContent)

# googletest
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        master
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	add_subdirectory(
		${googletest_SOURCE_DIR} 
		${googletest_BINARY_DIR})
endif()

# sfml
set(BUILD_SHARED_LIBS false)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.5.1
	)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
	if (LINK_DEPS_STATIC)
		set(SFML_STATIC_LIBRARIES CACHE BOOL TRUE)
	endif()

    FetchContent_Populate(sfml)
    add_subdirectory(
		${sfml_SOURCE_DIR} 
		${sfml_BINARY_DIR})
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
)

# install
install(TARGETS ${PROJECT_NAME})
install(DIRECTORY "media" DESTINATION "bin")