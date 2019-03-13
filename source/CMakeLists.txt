if(NOT DEFINED RADIX_WINDOW_LIBRARIES)
  message(FATAL_ERROR "Please compile using the repo's root CMakeLists.txt")
endif()

set(D ${CMAKE_CURRENT_SOURCE_DIR})

set(RADIX_WINDOW_SOURCES
  ${RADIX_WINDOW_SOURCES}
  ${D}/Window.cpp
  PARENT_SCOPE
)
