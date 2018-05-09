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

  ros::init(argc, argv, "ReadCam");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::String>("ReadCam", 1000);
  ros::Rate loop_rate(30);
  
  VideoCapture capture(0);
  while(ros::ok()){
    Mat frame;
    capture >>frame;
    if(frame.empty()){
      ROS_INFO("cannot read Cam");
      break;
    }
    imshow("Cam",frame);
    waitKey(30); 
    
    ros::spinOnce();
    loop_rate.sleep();   
  }
  return 0; 
  
}