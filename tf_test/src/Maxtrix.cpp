#include<ros/ros.h>
#include<tf/tf.h>
using namespace std;

int main(int argc, char** argv)
{
//初始化
ros::init(argc, argv, "Quaternion2Euler");
ros::NodeHandle node;
//第3部分,定义旋转矩阵
cout<<"第三部分,定义旋转矩阵"<<endl;
//3.1由旋转轴和旋转角来估计四元数
tf::Quaternion q2(1, 0, 0, 0);
tf::Matrix3x3 matrix;
tf::Vector3 v6, v7, v8;
matrix.setRotation(q2);
v6 = matrix[0];
v7 = matrix[1];
v8 = matrix[2];
std::cout<<"四元数q2对应的旋转矩阵M:"<<v6[0]<<","<<v6[1]<<","<<v6[2]<<std::endl;
std::cout<<"                       "<<v7[0]<<","<<v7[1]<<","<<v7[2]<<std::endl;
std::cout<<"                       "<<v8[0]<<","<<v8[1]<<","<<v8[2]<<std::endl;
//3.2通过旋转矩阵求欧拉角
tfScalar m_yaw, m_pitch, m_roll;
matrix.getEulerYPR(m_yaw, m_pitch, m_roll);
std::cout<<"由旋转矩阵M,得到欧拉角rpy("<<m_roll<<","<<m_pitch<<","<<m_yaw<<")"<<std::endl;
return 0;
return 0;
}
