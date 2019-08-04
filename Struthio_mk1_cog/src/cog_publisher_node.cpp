//headers for ROS
#include <ros/ros.h>

//headers in this package
#include "cog_publisher.h"
//#define _GLIBCXX_USE_CXX11_ABI 0
#define _GLIBCXX_USE_DUAL_ABI 1

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cog_publisher");
  cog_publisher center_of_gravity_publisher = cog_publisher();
  ros::Rate rate(center_of_gravity_publisher.get_publish_rate());
  while(ros::ok())
  {
    center_of_gravity_publisher.publish();
    rate.sleep();
  }
  return 0;
} 

