
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
#include "std_msgs/Float64.h"
#include <stdlib.h>
#include <iostream>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PointStamped.h>
#include <sensor_msgs/PointCloud.h>
using namespace std;
#include <math.h>
float jointPos;
  //parameters for calculate COG of robot
  //double cog_robot_x = 0;
  //double cog_robot_y = 0;
  //double cog_robot_z = 0;

void JointStates_callback(const sensor_msgs::JointState::ConstPtr& msg){
        for(int i=0; i<7;i++){
                ROS_INFO("--- [%s] :[%f] DEG",msg->name[i].c_str(),msg->position[i]*(180/M_PI));
       jointPos=msg->position[i];
       	}


}


int main(int argc, char **argv){
        ros::init(argc,argv,"jointControl");
        ros::NodeHandle nh_s;
        ros::Subscriber sub =nh_s.subscribe("Struthio_mk1/joint_states",100,JointStates_callback);
        vector<double> x(0),y(0);
        ros::Rate rate(100); //100 per 1second


	

     //   ros::init(argc,argv,"joint_control");
        ros::NodeHandle nh_p;
        ros::Publisher pub_battery =  nh_p.advertise<std_msgs::Float64>("/Struthio_mk1/joint_battery_position_controller/command",10);
        ros::Publisher pub_upperLegL =  nh_p.advertise<std_msgs::Float64>("/Struthio_mk1/joint_upperLegL_position_controller/command",10);
        ros::Publisher pub_lowerLegL =  nh_p.advertise<std_msgs::Float64>("/Struthio_mk1/joint_lowerLegL_position_controller/command",10);
        ros::Publisher pub_upperLegR =  nh_p.advertise<std_msgs::Float64>("/Struthio_mk1/joint_upperLegR_position_controller/command",10);
        ros::Publisher pub_lowerLegR =  nh_p.advertise<std_msgs::Float64>("/Struthio_mk1/joint_lowerLegR_position_controller/command",10);
        ros::Publisher pub_footL =  nh_p.advertise<std_msgs::Float64>("/Struthio_mk1/joint_footL_position_controller/command",10);
        ros::Publisher pub_footR =  nh_p.advertise<std_msgs::Float64>("/Struthio_mk1/joint_footR_position_controller/command",10);
        //ros::Rate loop_rate(20); // 20 per seconds
  uint32_t shape = visualization_msgs::Marker::CUBE;
  ros::Publisher marker_pub = nh_p.advertise<visualization_msgs::Marker>("visualization_marker", 1);
        int frameid=0;

//      plt::plot(x,y,"--r"); //init plot
        while(ros::ok()){
 

//////////////////PUBLISHER/////////////////////
                visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/my_frame";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "joint_control";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD and DELETE
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z =  jointPos;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    marker_pub.publish(marker);

                std_msgs::Float64 msg_battery;
                std_msgs::Float64 msg_upperLegL;
                std_msgs::Float64 msg_lowerLegL;
                std_msgs::Float64 msg_upperLegR;
                std_msgs::Float64 msg_lowerLegR;
                std_msgs::Float64 msg_footL;
                std_msgs::Float64 msg_footR;

                msg_battery.data= sin(3.14/50*frameid);
                msg_upperLegL.data= 0;
                msg_lowerLegL.data= 0;
                msg_footL.data= 0;
                msg_upperLegR.data= 0;
                msg_lowerLegR.data= 0;
                msg_footR.data=0;

                pub_battery.publish(msg_battery);
                pub_upperLegL.publish(msg_upperLegL);
                pub_lowerLegL.publish(msg_lowerLegL);
                pub_upperLegR.publish(msg_upperLegR);
                pub_lowerLegR.publish(msg_lowerLegR);
                pub_footL.publish(msg_upperLegR);
                pub_footL.publish(msg_lowerLegR);

               // ros::spinOnce();
                frameid++;
               // loop_rate.sleep();

///////////////////////////////////////////////////////////

 		//j.SetTestPos(1);
                ros::spinOnce();
                rate.sleep();
        }

        return 0;
}



