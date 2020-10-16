cmake_minimum_required (VERSION 3.18)

project ("application-test")

add_executable (${PROJECT_NAME} "Main.cpp")

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME}
  PRIVATE
    gtest
)