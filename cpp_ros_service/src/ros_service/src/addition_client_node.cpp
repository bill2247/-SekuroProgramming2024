#include "ros/ros.h"
#include "ros_service/position_data.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "Addition_Service_Client_Node");
    ros::NodeHandle nh;
    
    ros::ServiceClient client = nh.serviceClient<ros_service::position_data>("position_data");

    ros_service::position_data srv;
    srv.request.komponenX = 12;
    srv.request.komponenY = 3;
    srv.request.komponenZ = 4;

    if(client.call(srv)){
        ROS_INFO("The absolute value of your position is: %ld", srv.response.magnitude);
    }
    else{
        ROS_INFO("Failed to call the service");
        return 1;
    }

    return 0;
}