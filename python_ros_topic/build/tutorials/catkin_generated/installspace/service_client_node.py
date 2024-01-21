import rospy
from tutorials.srv import multiplier, multiplierResponse

def multiplier_client(x, y):
    rospy.init_node("client_node")
    rospy.wait_for_service("multiplier")
    rate = rospy.rate(1)
    while not rospy.is_shutdown():
        try:
            multiply_two_int = rospy.ServiceProxy("multiplier", multiplier)
            response = multiply_two_int(x,y)
            rospy.loginfo(response.result)
            rate.sleep(1)
        except rospy.ServiceException as e:
            print("Service call failed %s", e)
            

if __name__ == '__main__':
    multiplier_client(7,2)