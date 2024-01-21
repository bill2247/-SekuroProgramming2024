import rospy
from ros_topic.srv import magnitude, magnitudeResponse

def magnitude_client(x, y, z):
    rospy.init_node("client_node")
    rospy.wait_for_service("magnitude")
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        try:
            magnitude_a_point = rospy.ServiceProxy("magnitude",magnitude)
            response = magnitude_a_point(x,y,z)
            rospy.loginfo(response.result)
            rate.sleep()
        except rospy.ServiceException as e:
            print("Service call failed %s", e)

if __name__ == '__main__':
    magnitude_client(3,4,12)