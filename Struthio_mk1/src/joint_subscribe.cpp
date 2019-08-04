//#include "/home/sumiki/matplotlib-cpp-starter/matplotlibcpp.h"
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
#include "joint_subscribe.h"
using namespace std;
#include <math.h>

double roll_plt(0),x(0);
//namespace plt = matplotlibcpp;
//double pos=1;
void JointStates_callback(const sensor_msgs::JointState::ConstPtr& msg){
	for(int i=0; i<7;i++){
		ROS_INFO("--- [%s] :[%f] DEG",msg->name[i].c_str(),msg->position[i]*(180/M_PI));
	}
        double pos=msg->position[1];

	
}

int main(int argc, char **argv){
	ros::init(argc,argv,"joint_subscribe");
	ros::NodeHandle nh;
	ros::Subscriber sub =nh.subscribe("Struthio_mk1/joint_states",100,JointStates_callback);
	vector<double> x(0),y(0);
	ros::Rate rate(100); //100 per 1second

//	plt::plot(x,y,"--r"); //init plot
	while(ros::ok()){
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}
