#include<ros/ros.h>
#include<tf/tf.h>
using namespace std;
int main(int argc, char** argv)
{
//初始化
ros::init(argc, argv, "Euler2Quatation");
ros::NodeHandle node;
geometry_msgs::Quaternion q;
double roll, pitch, yaw;
while(ros::ok())
{
//输入一个相对原点的位置
cout<<"输入的欧拉角:roll, pitch, yaw:";
cin>>roll>>pitch>>yaw;
//输入欧拉角,转化成四元数在终端输出
q = tf::createQuaternionMsgFromRollPitchYaw(roll, pitch, yaw);
cout<<"输出的四元数为：w="<<q.w<<",x="<<q.x<<",y="<<q.y<<",z="<<q.z<<std::endl;
ros::spinOnce();
}
return 0;
}
