cmake_minimum_required(VERSION 3.7)
include(FetchContent)

project(foo)

set(
    SOURCES
    src/main.cpp
    src/mainWindow.cpp
)

if(WIN32)
    add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
else()
    add_executable(${PROJECT_NAME} ${SOURCES})
endif()

###########   wxWidgets   ###########

if(WIN32)

  set(wxBUILD_SHARED OFF CACHE BOOL "Build wx libraries as shared libs")
  set(wxBUILD_PRECOMP OFF CACHE BOOL "Use precompiled headers")
  set(wxBUILD_MONOLITHIC OFF CACHE BOOL "Build a single library")

  FetchContent_Declare(
      wxWidgets 
      GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
      GIT_TAG        v3.1.4
      GIT_SHALLOW     TRUE
  )

  FetchContent_GetProperties(wxWidgets)
  FetchContent_MakeAvailable(wxWidgets)

  target_link_libraries(${PROJECT_NAME}
      wxbase
      wxcore
      wxnet
  )

else()
  find_package(wxWidgets COMPONENTS core base xrc REQUIRED)
  include(${wxWidgets_USE_FILE})
  target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
endif()

install (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)