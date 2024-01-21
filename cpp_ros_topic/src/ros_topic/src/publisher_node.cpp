#include "ros/ros.h"
#include "ros_topic/person_data.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "Publisher");
    ros::NodeHandle nh;
    
    ros::Publisher topic_pub = nh.advertise <ros_topic::person_data>("ros_topic_latihan", 1000);
    ros::Rate loop_rate(1);

    while(ros::ok()){
        ros_topic::person_data person_data;
        person_data.usia = 18;
        person_data.tinggi = 174.5;
        person_data.nama = "Sabilul Huda";
        person_data.kehadiran = true;

        topic_pub.publish(person_data);
        ros::spinOnce();
        loop_rate.sleep();
    };

    return 0;
}