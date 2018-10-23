#include<ros/ros.h>
#include<tf/tf.h>
using namespace std;
//退出用Ctrl+z
int main(int argc, char** argv)
{
ros::init(argc, argv, "Euler2Quaternion");
ros::NodeHandle node;
cout<<"第二部分:定义四元数"<<endl;
//2.1由欧拉角计算四元数
tfScalar yaw, pitch, roll;
yaw = 0; pitch = 0; roll = 0;
cout<<"欧拉角rpy("<<roll<<","<<pitch<<","<<yaw<<")";
tf::Quaternion q;
q.setRPY(yaw, pitch, roll);
cout<<",转化为四元数1:"<<"("<<q[3]<<","<<q[0]<<","<<q[1]<<","<<q[2]<<")"<<endl;
//2.2由四元数得到旋转轴
tf::Vector3 v5;
v5 = q.getAxis();
cout<<"四元数q的旋转轴v5"<<"("<<v5[0]<<","<<v5[1]<<","<<v5[2]<<")"<<endl;
//2.3由旋转轴和旋转角来估计四元数
tf::Quaternion q2;
q2.setRotation(v5, 1.570796);
cout<<"旋转轴v5和旋转角度90度,转化得到四元数q2:"<<"("<<q2[3]<<","<<q2[0]<<","<<q2[1]<<","<<q2[2]<<")"<<std::endl;
return 0;
}


