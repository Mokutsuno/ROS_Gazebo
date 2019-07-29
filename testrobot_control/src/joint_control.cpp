#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include <sensor_msgs/JointState.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc,char** argv)
{
 	ros::init(argc,argv,"joint_control");

	ros::NodeHandle n;
	//ros::Publisher pub = n.advertise<sensor_msgs::JointState>("/myTestRobot/upperLegL_joint_position_controller/command",10);
	ros::Publisher pub =  n.advertise<std_msgs::Float64>("/myTestRobot_simple_gazebo/upperLegL_joint_position_controller/command",10); 
	
	ros::Rate loop_rate(20); // 20 per seconds
	
	int frameid=0;
	while(ros::ok())
	{
		std_msgs::Float64 msg;
		//sensor_msgs::JointState js;
		//js.header.stamp = ros::Time::now();
		//js.name.resize(1);
		//js.name[0]="upperLegL_joint";
		//js.position.resize(1);
		//js.position[0]=sin(3.14159/50*frameid);
		//msg.frameID = frameid;
		msg.data=sin(3.14159/50*frameid);
		//pub.publish(js);
		pub.publish(msg);
		//ROS_INFO("%f",msg.data);
		ros::spinOnce();
		frameid++;
		loop_rate.sleep();
	}
	return 0;
}
