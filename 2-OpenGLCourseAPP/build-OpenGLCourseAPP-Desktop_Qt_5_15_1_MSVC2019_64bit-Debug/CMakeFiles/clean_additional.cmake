# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\OpenGLCourseAPP_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\OpenGLCourseAPP_autogen.dir\\ParseCache.txt"
  "OpenGLCourseAPP_autogen"
  )
endif()
