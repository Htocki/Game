cmake_minimum_required (VERSION 3.15)

set (HEADERS
  "include/Application.h"
)

set (SOURCES
  "src/Application.cpp"
  "src/Main.cpp"
)

project ("application")

add_executable (${PROJECT_NAME}
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
    controller
    model
    view
    utility
)

file (
  COPY "${CMAKE_SOURCE_DIR}/media" 
  DESTINATION "${PROJECT_BINARY_DIR}"
)