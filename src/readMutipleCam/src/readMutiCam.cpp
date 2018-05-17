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

  ros::init(argc, argv, "readMutipleCam");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<std_msgs::String>("ReadMultiCam", 1000);
  ros::Rate loop_rate(30);
  VideoCapture cap1(0);
  VideoCapture cap2(1);
  VideoCapture cap3(2);
  Mat frame1,frame2,frame3;
  
  /*
  int Cam_Num = 3;
  cap1(0);
  if(Cam_Num==2){
    cap2(1);
  }
  else if(Cam_Num==3){
    cap2(1);
    cap3(2);
  }*/
  namedWindow("Cam1");
  namedWindow("Cam2");
  namedWindow("Cam3");
  while(ros::ok()){
    
    cap1 >> frame1;
    cap2 >> frame2;
    cap3 >> frame3;
    if(frame1.empty()){
      ROS_INFO("cannot read Cam1");
      break;
    }
    imshow("Cam1",frame1);
    waitKey(30); 
    
    if(frame2.empty()){
      ROS_INFO("cannot read Cam2");
      break;
    }
    imshow("Cam2",frame2);
    waitKey(30);
    
    if(frame3.empty()){
      ROS_INFO("cannot read Cam3");
      break;
    }
    imshow("Cam3",frame3);
    waitKey(30);
    
    ros::spinOnce();
    loop_rate.sleep();   
  }
  return 0; 
  
}
