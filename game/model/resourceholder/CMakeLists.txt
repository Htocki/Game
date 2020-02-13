cmake_minimum_required (VERSION 3.15)

project ("resourceholder")

add_library (${PROJECT_NAME} INTERFACE)

target_sources (${PROJECT_NAME} 
    INTERFACE
        "include/Enums.h"
        "include/ResourceHolder.h"
    )

target_include_directories(${PROJECT_NAME}
    INTERFACE
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	)