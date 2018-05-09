cmake_minimum_required(VERSION 2.8.3)
project(kcf)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)
find_package(OpenCV REQUIRED)

catkin_package(

)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${kcf_SOURCE_DIR}/src/
)


add_executable(${PROJECT_NAME}_node src/main.cpp src/gradientMex.cpp src/kcf.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)

add_executable(${PROJECT_NAME}_listener_node src/listener.cpp)
target_link_libraries(${PROJECT_NAME}_listener_node
  ${catkin_LIBRARIES}
)