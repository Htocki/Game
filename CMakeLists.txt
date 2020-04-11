cmake_minimum_required (VERSION 3.15)

project ("game")

add_executable (${PROJECT_NAME}
    "game/Application.h"
    "game/Application.cpp"

    "game/utility/include/Subject.h"
    "game/utility/include/Observer.h"
    "game/utility/src/Subject.cpp"
    
    "game/controller/include/Controller.h"
    "game/controller/include/InputPlayer.h"
    "game/controller/src/Controller.cpp"
    "game/controller/src/InputPlayer.cpp"

    "game/model/include/Assets.h"
    "game/model/include/Engine.h"
    "game/model/include/Player.h"
    "game/model/src/Assets.cpp"
    "game/model/src/Engine.cpp"
    "game/model/src/Player.cpp"

    "game/view/include/RenderPlayer.h"
    "game/view/include/View.h"
    "game/view/src/RenderPlayer.cpp"
    "game/view/src/View.cpp"

    "game/Main.cpp"
    )

include_directories ("game/utility/include")
include_directories ("game/controller/include")
include_directories ("game/model/include")
include_directories ("game/view/include")

set_target_properties (${PROJECT_NAME}
    PROPERTIES
        set (CMAKE_CXX_STANDARD 17)
        set (CMAKE_CXX_STANDARD_REQUIRED ON)
    )

if (MSVC)
    add_definitions (/W4)
    message ("msvc compiler")
elseif (CMAKE_COMPILER_IS_GNUCXX)
    add_definitions (-Wall -pedantic)
    message ("gcc compiler")
else()
    message ("Unknown compiler")
endif()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include (CTest)
endif()


find_package(SFML 2.5.1
    COMPONENTS
        system
        graphics
        window
        audio
        network
    )

target_link_libraries (${PROJECT_NAME}
    PUBLIC
        sfml-graphics
        sfml-system
        sfml-window
    )

# install
# install (TARGETS ${PROJECT_NAME})
install (
    DIRECTORY
        "${CMAKE_SOURCE_DIR}/media"
    DESTINATION 
        "{CMAKE_SOURCE_DIR}/build"
    )
