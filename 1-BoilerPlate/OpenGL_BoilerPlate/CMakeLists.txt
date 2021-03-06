cmake_minimum_required(VERSION 3.5)

project(OpenGL_BoilerPlate LANGUAGES CXX)

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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt5OpenGL)
find_package(OpenGL)

find_package(GLEW)

#find_path(GLEW_INCLUDE_DIR C:/LIBS/glew-2.2.0/include/GL/Glew.h)
#find_library(GLEW_LIBRARY NAMES GLEW glew32 glew glew32s PATH_SUFFIXES lib64)


#if (GLEW_FOUND)
#    include_directories(${GLEW_INCLUDE_DIRS})
#    link_libraries(${GLEW_LIBRARIES})
#endif()



if(ANDROID)
  add_library(${PROJECT_NAME} SHARED
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    myglwidget.cpp
    myglwidget.h
  )
else()
  add_executable(${PROJECT_NAME}
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    myglwidget.cpp
    myglwidget.h
  )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OPENGL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
