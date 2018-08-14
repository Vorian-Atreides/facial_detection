cmake_minimum_required(VERSION 2.8)
#set(OpenCV_STATIC ON)
set(AppName FacialDetection)

project(${AppName})

set(IncludesDir ${PROJECT_SOURCE_DIR}/includes)
file(GLOB_RECURSE Sources ${PROJECT_SOURCE_DIR}/sources/*.cpp)
file(GLOB_RECURSE Includes ${IncludesDir}/*.h)

find_package(OpenCV REQUIRED)

include_directories(
  ${OpenCV_INCLUDE_DIRS}
  ${IncludesDir}
)

add_executable(
  ${AppName}
  ${Sources}
)

target_link_libraries(
  ${AppName}
  ${OpenCV_LIBS}
)
