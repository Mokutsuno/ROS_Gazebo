//#include "/home/sumiki/matplotlib-cpp-starter/matplotlibcpp.h"
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
using namespace std;
#include <math.h>

double roll_plt(0),x(0);
//namespace plt = matplotlibcpp;

void JointStates_callback(const sensor_msgs::JointState::ConstPtr& msg){
	//const std::vector<std::string> &names = msg->name;
	ROS_INFO("--- [%f] RAD,[%f] DEG",msg->position[0],msg->position[0]*(180/M_PI));
	//	tf::Quaternion q;
	/*for(size_t i=0; i<names.size(); ++i){
      		if(names[i].compare("testrobot_control::upperLegL") == 0){
        		msg->pose[i];
        		 q =tf::Quaternion(msg->pose[i].orientation.x,msg->pose[i].orientation.y,msg->pose[i].orientation.z,msg->pose[i].orientation.w);
        		break;
      		}
    	}*/
	//tf::Quaternion q(msg->name pose[1].orientation.x,msg->pose[1].orientation.y,msg->pose[1].orientation.z,msg->pose[1].orientation.w);
	//tf::Matrix3x3 m(q);
	//double roll,pitch,yaw;
	//m.getRPY(roll,pitch,yaw);
	//roll = roll*(180/M_PI);
	//pitch = pitch*(180/M_PI);
	//yaw = yaw*(1800/M_PI);
	//ROS_INFO(" ---  roll: [%f],pich: [%f],yaw: [%f]", roll,pitch,yaw);
	//roll_plt = roll;
	//pitch_plt = pitch;
	//yaw_plt =yaw;

//	plt::pause(0.1); //plot update
//	x=x+0.1;
}

int main(int argc, char **argv){
	ros::init(argc,argv,"joint_subscribe");
	ros::NodeHandle nh;
	ros::Subscriber sub =nh.subscribe("myTestRobot_simple_gazebo/joint_states",100,JointStates_callback);
	vector<double> x(0),y(0);
	ros::Rate rate(100); //100 per 1second

//	plt::plot(x,y,"--r"); //init plot
	while(ros::ok()){
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}
