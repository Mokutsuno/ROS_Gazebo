#include "jointState.h"
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
using namespace std;
#include <math.h>

double roll_plt(0),x(0);
//namespace plt = matplotlibcpp;
float exPos=0;
void JointStates_callback(const sensor_msgs::JointState::ConstPtr& msg){
	//JointState j;
	//j.SetTestPos(1);
	for(int i=0; i<7;i++){
		ROS_INFO("--- [%s] :[%f] DEG",msg->name[i].c_str(),msg->position[i]*(180/M_PI));
        //testPos=msg->position[i];
	JointState::pos=msg->position[i];
	//exPos=msg->position[i];
	//ROS_INFO("[%f]",exPos);
	}

	
}

int main(int argc, char **argv){
	//JointState j;
       exPos=100;
        ros::init(argc,argv,"joint_subscribe");
	ros::NodeHandle nh;
	ros::Subscriber sub =nh.subscribe("Struthio_mk1/joint_states",100,JointStates_callback);
	vector<double> x(0),y(0);
	ros::Rate rate(100); //100 per 1second

//	plt::plot(x,y,"--r"); //init plot
	while(ros::ok()){
		//j.SetTestPos(1);
		ros::spinOnce();
		rate.sleep();
	}

	return 0;
}
