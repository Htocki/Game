cmake_minimum_required (VERSION 3.15)

project ("game")

add_executable (${PROJECT_NAME} "src/Main.cpp")

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
    sfml-window
    model
    view
    utility
)

file (
  COPY "${CMAKE_SOURCE_DIR}/media" 
  DESTINATION "${PROJECT_BINARY_DIR}"
)

add_subdirectory ("lib")