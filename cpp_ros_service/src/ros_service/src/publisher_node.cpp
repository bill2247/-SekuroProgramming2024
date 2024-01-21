#include "ros/ros.h"
#include "ros_service/position_data.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;
    
    ros::Publisher topic_pub = nh.advertise <ros_service::position_data>("ros_service_latihan", 1000);
    ros::Rate loop_rate(1);

    while(ros::ok()){
        ros_service::position_data position_data;
        position_data.komponenX = 12;
        position_data.komponenY = 3;
        position_data.komponenZ = 4;

        topic_pub.publish(position_data);
        ros::spinOnce();
        loop_rate.sleep();
    };

    return 0;
}