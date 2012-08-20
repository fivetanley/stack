cmake_minimum_required(VERSION 2.6)
project(STACK_TESTS C)

include_directories(${STACK_TESTS_SOURCE_DIR}/include)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
SET(CMAKE_C_FLAGS_DEBUG "-DDEBUG -g3 -ggdb3")

SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)

add_library(stack STATIC stack.c)

add_executable(stack-test stack-test.c stack)

INSTALL(TARGETS stack
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
