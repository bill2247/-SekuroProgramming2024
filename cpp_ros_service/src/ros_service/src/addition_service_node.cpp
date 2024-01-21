#include "ros/ros.h"
#include "ros_service/position_data.h"
#include "math.h"

bool absolute(ros_service::position_data::Request &req, ros_service::position_data::Response &res){
    res.magnitude = pow(req.komponenX*req.komponenX + req.komponenY*req.komponenY + req.komponenZ*req.komponenZ, 0.5);
    return true;
};

int main(int argc, char **argv){
    ros::init(argc, argv, "Service_Node");
    ros::NodeHandle nh;
    
    ros::ServiceServer service = nh.advertiseService("position_data", magnitude);

    ros::spin();

    return 0;
}