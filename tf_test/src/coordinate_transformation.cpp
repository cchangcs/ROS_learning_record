#include<ros/ros.h>
#include<tf/tf.h>

using namespace std;
//退出用:Ctrl+z
int main(int argc, char** argv)
{
//初始化
ros::init(argc, argv, "coordinate_transformation");
ros::NodeHandle node;
tf::Vector3 v1(1, 1, 1);
tf::Vector3 v2(1, 0, 1);

//第一部分,定义空间点和空间向量
cout<<"第一部分,定义空间点和空间向量"<<endl;
//1.1计算两个向量的点积
cout<<"向量v1:"<<"("<<v1[0]<<","<<v1[1]<<","<<v1[2]<<")";
cout<<"向量2:"<<"("<<v2[0]<<","<<v2[1]<<","<<v2[2]<<")"<<endl;
cout<<"两个向量的点积:"<<tfDot(v1, v2)<<endl;

//1.2计算向量的模
cout<<"向量2的模值:"<<v2.length()<<endl;
//1.3求已知向量同方向的单位向量
tf::Vector3 v3;
v3 = v2.normalize();
cout<<"与向量v2同方向的单位向量v3:"<<"("<<v3[0]<<","<<v3[1]<<","<<v3[2]<<")"<<endl;
//1.4 计算两个向量的夹角
cout<<"两个向量的夹角(弧度):"<<tfAngle(v1, v2)<<endl;
//1.5计算两个向量的距离
cout<<"两个向量的距离:"<<tfDistance2(v1, v2)<<endl;
//1.6计算两个向量的乘积
tf::Vector3 v4;
v4 = tfCross(v1, v2);
cout<<"两个向量的乘积v4"<<"("<<v4[0]<<","<<v4[1]<<","<<v4[2]<<")"<<endl;
return 0;
}
