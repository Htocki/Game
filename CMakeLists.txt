cmake_minimum_required (VERSION 3.15)

set (HEADERS
	"include/Graphics/Label.hpp"
	"include/Graphics/Widget.hpp"
	"include/Utility/Generator.hpp"
	"include/Utility/ToString.hpp"
	"include/Utility/ToString.inl"
	"include/Enums.hpp"
	"include/Game.hpp"
	"include/GameObject.hpp"
	"include/Player.hpp"
	"include/RandomizedMatrix.hpp"
	"include/ResourceHolder.hpp"
	"include/ResourceHolder.inl"
	"include/Spaceship.hpp"
	"include/Statistic.hpp"
	"include/Tilemap.hpp"
	)

set (SOURCES 
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

project ("game")

add_executable (${PROJECT_NAME} ${HEADERS} ${SOURCES})

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
		${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML-2.5.1/include
	)

if (MSVC)
	add_definitions (/W4)
elseif (CMAKE_COMPILER_IS_GNUCXX)
	add_definitions (-Wall -pedantic)
else ()
	message ("Unknown compiler")
endif ()

if (MSVC)
	set_property(TARGET ${PROJECT_NAME} APPEND_STRING
		PROPERTY LINK_FLAGS 
			"/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
	)
endif ()

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

if (MSVC)  
	set (SFML_DIR "lib/SFML-2.5.1/lib/cmake/SFML")
endif ()

find_package (SFML 2.5.1 
	COMPONENTS 
		graphics 
		window 
		system 
		audio 
		network 
	REQUIRED
	)

target_link_libraries(${PROJECT_NAME} 
	sfml-graphics 
	sfml-window 
	sfml-system 
	sfml-audio 
	sfml-network
	)

install(TARGETS ${PROJECT_NAME})
install(DIRECTORY "lib/SFML-2.5.1/bin/" DESTINATION "bin")
install(DIRECTORY "media" DESTINATION "bin")