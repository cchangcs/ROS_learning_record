#include<ros/ros.h>
#include "nav_msgs/Odometry.h"
#include<tf/tf.h>

using namespace std;

int main(int argc, char** argv)
{
//初始化
ros::init(argc, argv, "Quaternion2Euler");
ros::NodeHandle node;
nav_msgs::Odometry position;
tf::Quaternion RQ2;
double roll, pitch, yaw;

while(ros::ok())
{
cout<<"输入一个相对于原点的四元数:w, x, y, z:";
cin>>position.pose.pose.orientation.w>>position.pose.pose.orientation.x>>position.pose.pose.orientation.y>>position.pose.pose.orientation.z;
//输入四元数,转换成欧拉角并在终端输出
tf::quaternionMsgToTF(position.pose.pose.orientation, RQ2);
// tf::Vector3 m_vector3; 方法2
 // m_vector3=RQ2.getAxis();
  tf::Matrix3x3(RQ2).getRPY(roll,pitch,yaw);  
  std::cout<<"输出的欧拉角为：roll="<<roll<<",pitch="<<pitch<<",yaw="<<yaw<<std::endl;
  //std::cout<<"输出欧拉角为：roll="<<m_vector3[0]<<",pitch="<<m_vector3[1]<<",yaw="<<m_vector3[2]<<std::endl;
  ros::spinOnce();
}

return 0;
}
