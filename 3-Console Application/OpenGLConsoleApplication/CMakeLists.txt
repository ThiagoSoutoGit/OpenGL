cmake_minimum_required(VERSION 3.8)

project(OpenGLConsoleApplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OpenGLConsoleApplication main.cpp)

include_directories("C:/Program Files (x86)/GLFW/include")
#set(CMAKE_PREFIX_PATH C:/Program Files (x86)/GLFW/lib)
set(CMAKE_PREFIX_PATH C:/LIBS/glfw-3.3.2.bin.WIN32/include/GLFW/)

#add_subdirectory(C:/LIBS/glfw-3.3.2.bin.WIN32/include/GLFW/)

#lib-vc2019

set(CMAKE_MODULE_PATH C:/Program Files/CMake/share/cmake-3.17/Modules)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

#Encontrando y linkeando GLEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_directories(${GLEW_LIBRARY_DIRS})
add_definitions(${GLEW_DEFINITIONS})
if(NOT GLEW_FOUND)
message(Error " GLEW not found")
endif(NOT GLEW_FOUND)

##Encontrando y linkeando glfw3
find_package(GLFW 3.0 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})
add_definitions(${GLFW_DEFINITIONS})

#include_directories("C:/Program Files (x86)/GLFW/include")

if(NOT GLFW_FOUND)
message(Error "GLFW not found")
endif(NOT GLFW_FOUND)

#include_directories("C:/Program Files (x86)/GLFW/include")

#set( ENKITS_BUILD_EXAMPLES OFF CACHE BOOL "Build basic example applications" )
#set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL  "GLFW lib only" )
#set( GLFW_BUILD_TESTS OFF CACHE BOOL  "GLFW lib only" )
#set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
#set( GLFW_BUILD_INSTALL OFF CACHE BOOL  "GLFW lib only" )

#add_subdirectory( C:/Program Files/GLFW )

##Encontrando y linkeando glm

#find_package(GLM REQUIRED)
#include_directories(${GLM_INCLUDE_DIRS})
#link_directories(${GLM_LIBRARY_DIRS})
#add_definitions(${GLM_DEFINITIONS})

#if(NOT GLM_FOUND)
#message(Error "GLM not found")
#endif(NOT GLM_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

if(NOT OpenGL_FOUND)
message(Error "OpenGL not found")
endif(NOT OpenGL_FOUND)

#Incluir archivos

#add_executable(OpenGLConsoleApplication main.cpp)

#target_link_libraries(OpenGLConsoleApplication ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${GLM_LIBRARIES})

#glfw3

target_link_libraries(OpenGLConsoleApplication ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} GLEW::GLEW )

