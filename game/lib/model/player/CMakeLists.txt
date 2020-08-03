cmake_minimum_required (VERSION 3.15)

set (HEADERS
  "include/MovingLeftPlayerState.h"
  "include/MovingRightPlayerState.h"
  "include/Player.h"
  "include/PlayerState.h"
  "include/StandingPlayerState.h"
)

set (SOURCES
  "src/MovingLeftPlayerState.cpp"
  "src/MovingRightPlayerState.cpp"
  "src/Player.cpp"
  "src/StandingPlayerState.cpp"
)

project ("player")

add_library (${PROJECT_NAME}
  STATIC
    ${INCLUDE}
    ${SOURCES}
)

set_target_properties (${PROJECT_NAME}
  PROPERTIES
    set (CMAKE_CXX_STANDARD 20)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

target_include_directories (${PROJECT_NAME}
  PUBLIC 
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries (${PROJECT_NAME} 
  PUBLIC
    sfml-graphics
    sfml-system
    sfml-window
    utility
)