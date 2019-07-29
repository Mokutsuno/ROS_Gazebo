#include "/home/sumiki/matplotlib-cpp-starter/matplotlibcpp.h"
#include <ros/ros.h>
#include <gazebo_msgs/ModelStates.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
using namespace std;
#include <math.h>

double roll_plt(0),x(0);
namespace plt = matplotlibcpp;

void modelStates_callback(const gazebo_msgs::ModelStates::ConstPtr& msg){
	tf::Quaternion q(msg->pose[1].orientation.x,msg->pose[1].orientation.y,msg->pose[1].orientation.z,msg->pose[1].orientation.w);
	tf::Matrix3x3 m(q);
	double roll,pitch,yaw;
	m.getRPY(roll,pitch,yaw);
	roll_plt = roll;
	//pitch_plt = pitch;
	//yaw_plt =yaw;

	plt::pause(0.1); //plot update
	x=x+0.1;
}

int main(int argc, char **argv){
	ros::init(argc,argv,"joint_subscribe");
	ros::NodeHandle nh;
	ros::Subscriber sub =nh.subscribe("/gazebo/model_states",100,modelStates_callback);
	vector<double> x(0),y(0);
	ros::Rate rate(100); //100 per 1second

	plt::plot(x,y,"--r"); //init plot
	while(ros::ok()){
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}
