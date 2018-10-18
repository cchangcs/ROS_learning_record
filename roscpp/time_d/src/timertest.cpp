#include<ros/timer.h>
#include<ros/duration.h>
#include<ros/ros.h>

void callback1(const ros::TimerEvent&)
{
ROS_INFO("Callback 1 triggered");
}

void callback2(const ros::TimerEvent&)
{
ROS_INFO("Callback 2 triggered");
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "talker"); ros::NodeHandle n;
 
ros::Timer timer1 = n.createTimer(ros::Duration(0.1), callback1);	//timer1每0.1s触发 一次callback1函数
ros::Timer timer2 = n.createTimer(ros::Duration(1.0), callback2);	//timer2每1.0s触发 一次callback2函数
ros::spin();	//千万别忘了spin，只有spin了才能真正去触发回调函数 return 0;
}

