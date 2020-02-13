cmake_minimum_required (VERSION 3.15)

set (HEADERS
	"game/model/include/Enums.h"
	"game/model/include/Game.h"
	"game/model/include/GameObject.h"
	"game/model/include/Player.h"
	"game/model/include/ResourceHolder.h"
	"game/model/include/Spaceship.h"
	"game/model/include/Statistic.h"
	"game/utility/include/Generator.h"
	"game/utility/include/RandomizedMatrix.h"
	"game/utility/include/ToString.h"
	"game/view/include/Label.h"
	"game/view/include/Tilemap.h"
	"game/view/include/Widget.h"
	)

set (SOURCES 
	"game/model/src/Game.cpp"
	"game/model/src/GameObject.cpp"
	"game/model/src/Player.cpp"
	"game/model/src/Spaceship.cpp"
	"game/model/src/Statistic.cpp"
	"game/utility/src/RandomizedMatrix.cpp"
	"game/view/src/Label.cpp"
	"game/view/src/Tilemap.cpp"
	"game/view/src/Widget.cpp"
	"game/Main.cpp"
	)

project("game")

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT_NAME}
	PRIVATE
		"game/model/include"
		"game/utility/include"
		"game/view/include"
	)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
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