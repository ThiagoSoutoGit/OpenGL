cmake_minimum_required(VERSION 3.5)

project(ConsoleOpenGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(ConsoleOpenGL main.cpp)

#set(GLEW_DIR, "C:/glew-2.0.0/")

#set(GLEW_INCLUDE_DIR, "C:/glew-2.0.0/include/")
#set(GLEW_LIBRARY, "C:/glew-2.0.0/lib/")

##find_package(GLEW REQUIRED PATHS ${GLEW_DIR} NO_DEFAULT_PATH)

##find_package(GLEW REQUIRED)


#find_package(GLEW REQUIRED)
#if (GLEW_FOUND)
#    include_directories($(GLEW_INCLUDE_DIRS))
#endif()


#target_link_libraries(ConsoleOpenGL PRIVATE GLEW::GLEW)
#find_package(PkgConfig REQUIRED)
#pkg_search_module(GLFW REQUIRED glfw3)
#message(STATUS ${GLFW_INCLUDE_DIR})
