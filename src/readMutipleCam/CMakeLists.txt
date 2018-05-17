cmake_minimum_required(VERSION 2.8.3)
project(readMutipleCam)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)
find_package(OpenCV REQUIRED)


catkin_package(
)


include_directories(
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME} src/readMutiCam.cpp)
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)
