#include<ros/ros.h>
#include<topic1/gps.h> //自定义msg产生的文件
int main(int argc, char** argv)
{
	ros::init(argc, argv, "talker");//用于解析ROS参数，第三个参数为本节点名
	ros::NodeHandle nh;//实例化句柄，初始化node
	topic1::gps msg;//自定义消息并初始化
	ros::Publisher pub = nh.advertise<topic1::gps>("gps_info", 1);//创建publisher,往“gps_info”话题上发布消息
	ros::Rate loop_rate(1.0);//定义发布的频率，1HZ
	while(ros::ok()) //循环发布msg
	{
		//处理msg
		pub.publish(msg);//以1HZ的频率发布msg
		loop_rate.sleep();//根据前面定义的loop_rate,设置1s的暂停
	}	
	return 0;
}
