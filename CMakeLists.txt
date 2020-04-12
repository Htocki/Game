cmake_minimum_required (VERSION 3.15)

project ("game")

add_executable (
  ${PROJECT_NAME}
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

set_target_properties (
  ${PROJECT_NAME}
    PROPERTIES
      set (CMAKE_CXX_STANDARD 17)
      set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

if (MSVC)
  message ("Compiler: MSVC")
elseif (CMAKE_COMPILER_IS_GNUCXX)
  message ("Compiler: GCC")
else ()
  message ("Compiler: unknown")
endif ()

if (MSVC)
  add_definitions (/W4)
elseif (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic)
endif ()

if (MSVC) 
  set_property (
    TARGET 
      ${PROJECT_NAME} APPEND_STRING
    PROPERTY LINK_FLAGS 
      "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
  )
endif ()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include (CTest)
endif ()

#include extern libs
include (FetchContent)

# googletest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_GetProperties (googletest)
if (NOT googletest_POPULATED)
  FetchContent_Populate (googletest)
  add_subdirectory (
    ${googletest_SOURCE_DIR} 
    ${googletest_BINARY_DIR}
  )
endif ()

# sfml
set (BUILD_SHARED_LIBS false)

FetchContent_Declare (
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        master
)

FetchContent_GetProperties (sfml)
if (NOT sfml_POPULATED)
  if (LINK_DEPS_STATIC)
    set (SFML_STATIC_LIBRARIES CACHE BOOL TRUE)
  endif ()

  FetchContent_Populate (sfml)
  add_subdirectory (
    ${sfml_SOURCE_DIR} 
    ${sfml_BINARY_DIR}
  )
endif ()

target_link_libraries (
  ${PROJECT_NAME}
    PUBLIC
      sfml-graphics
      sfml-system
      sfml-window
)

file (
  COPY "${PROJECT_SOURCE_DIR}/media" 
  DESTINATION "${PROJECT_BINARY_DIR}"
)
