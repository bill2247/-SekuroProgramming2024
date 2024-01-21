#!/opt/ros/noetic/bin
import rospy
from std_msgs.msg import String
from tutorials.msg import Position

def talk_to_me():
    pub = rospy.Publisher("talking_topic", Position, queue_size = 10)
    rospy.init_node('publisher_node', anonymous = True)
    rate = rospy.Rate(1)
    rospy.loginfo("Publisher node started, now publishing messages")
    while not rospy.is_shutdown():
        msg = Position()
        msg.usia = 18
        msg.tinggi = 174.5
        msg.nama = "Sabilul Huda"
        msg.kehadiran = True
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        talk_to_me()
    except rospy.ROSInterruptException:
        pass