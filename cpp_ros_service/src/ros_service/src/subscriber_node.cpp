#include "ros/ros.h"
#include "ros_service/position_data.h"

void writeMsgToLog(const ros_service::position_data& position_data){
    ROS_INFO("POSITION X: %F", position_data.komponenX);
    ROS_INFO("POSITION Y: %F", position_data.komponenY);
    ROS_INFO("POSITION Z: %F", position_data.komponenZ);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "Subscriber");
    ros::NodeHandle nh;
    
    ros::Subscriber topic_sub = nh.subscribe("ros_service_latihan", 1000, writeMsgToLog);
    
    ros::spin();

    return 0;
}