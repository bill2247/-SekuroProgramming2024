import rospy
from ros_topic.srv import magnitude, magnitudeResponse

def callback(request):
    return magnitudeResponse((request.X**2 + request.Y**2 + request.Z**2)**0.5)

def magnitude():
    rospy.init_node("magnitude_service")
    service = rospy.servoice("magnitude", magnitude, callback)
    rospy.spin()

if __name__ == '__main__':
    magnitude()