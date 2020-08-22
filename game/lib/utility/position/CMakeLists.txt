cmake_minimum_required (VERSION 3.18)

set (HEADERS
  "include/Position.h"
)

project ("position")

add_library (${PROJECT_NAME}
  STATIC
    ${HEADERS}
)

set_target_properties(${PROJECT_NAME}
  PROPERTIES 
    LINKER_LANGUAGE CXX
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