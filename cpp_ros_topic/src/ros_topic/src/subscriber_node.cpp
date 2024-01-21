#include "ros/ros.h"
#include "ros_topic/person_data.h"

void writeMsgToLog(const ros_topic::person_data& person_data){
    ROS_INFO("usia: %li", person_data.usia);
    ROS_INFO("tinggi: %f", person_data.tinggi);
    ROS_INFO("nama: %s", person_data.nama.c_str());
    ROS_INFO("kehadiran: %d", person_data.kehadiran);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "Subscriber");
    ros::NodeHandle nh;
    
    ros::Subscriber topic_sub = nh.subscribe("ros_topic_latihan", 1000, writeMsgToLog);
    
    ros::spin();

    return 0;
}