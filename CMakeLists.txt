cmake_minimum_required(VERSION 2.8)

project(task)
set (CMAKE_CXX_STANDARD 14)


find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(include)

add_executable(${PROJECT_NAME} "main.cpp" "src/FocusStacking.cpp" "src/Filter.cpp" "src/Merge.cpp")
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

add_executable("test_blackwhite" "test_blackwhite.cpp" "src/FocusStacking.cpp" "src/Filter.cpp" "src/Merge.cpp")
target_link_libraries("test_blackwhite" ${OpenCV_LIBS})

add_executable("test_merge" "test_merge.cpp" "src/FocusStacking.cpp" "src/Filter.cpp" "src/Merge.cpp")
target_link_libraries("test_merge" ${OpenCV_LIBS})

