#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace cv;
using namespace std;

int main(int argc, char **argv){

  ros::init(argc, argv, "video");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::String>("video", 1000);
  ros::Rate loop_rate(30);
  
  int count = 0;
  VideoCapture capture("src/readvideo/a.mp4");
  while(ros::ok()){
    Mat frame;
    capture >>frame;
    if(frame.empty()){
      ROS_INFO("cannot find video");
      break;
    }
    imshow("readVideo",frame);
    waitKey(1); 
    
    ros::spinOnce();
    loop_rate.sleep();

    ++count;
    
  }
  return 0; 
  
}