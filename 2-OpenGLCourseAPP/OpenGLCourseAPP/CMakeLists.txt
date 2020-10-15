cmake_minimum_required(VERSION 3.5)

project(OpenGLCourseAPP LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#include_directories(${CMAKE_SOURCE_DIR}/External_Libraries/GLEW/include)
#link_directories(${CMAKE_SOURCE_DIR}/External_Libraries/GLEW/lib)

#add_subdirectory(External_Libraries/GLFW/)
#include_directories(External_Libraries/GLFW/include)

#include <C:/LIBS/GLEW/include/GL/glew.h>
#include <C:/LIBS/GLFW/include/GLFW/glfw3.h>


find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

find_package(OpenGL REQUIRED)
#include_directories ( include ${OPENGL_INCLUDE_DIR} )

find_package(GLEW)

if(ANDROID)
  add_library(OpenGLCourseAPP SHARED
    main.cpp
    widget.cpp
    widget.h
    widget.ui
  )
else()
  add_executable(OpenGLCourseAPP
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    glew32.dll
  )
endif()

target_link_libraries(OpenGLCourseAPP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets )


#glfw ${GLFW_LIBRARIES}
