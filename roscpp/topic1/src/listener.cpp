#include<ros/ros.h>
#include<topic1/gps.h>
#include<std_msgs/Float32.h>

void gpsCallback(const topic1::gps::ConstPtr &msg)
{
std_msgs::Float32 distance;//计算离原点的距离
distance.data = sqrt(pow(msg->x, 2) + pow(msg->y, 2));
ROS_INFO("Listener: Distance to origin = %f, state: %s", distance.data, msg->state.c_str());//输出
}

int main(int argc, char** argv)
{
ros::init(argc, argv, "listener");
ros::NodeHandle nh;
ros::Subscriber sub = nh.subscribe("gps_info", 1, gpsCallback);//设置回调函数gpsCallback
ros::spin();//ros::spin()用于调用所有可触发的回调函数，将进入循环，不会返回，类似于在循环里反复调用spinOnce() 
//而ros::spinOnce()只会去触发一次
return 0;
}
