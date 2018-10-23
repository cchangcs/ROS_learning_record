#include<ros/ros.h>
#include<tf/transform_broadcaster.h>
#include<tf/tf.h>

using namespace std;

int main(int argc, char** argv)
{
//初始化
ros::init(argc, argv, "tf_broadcast");
ros::NodeHandle node;
static tf::TransformBroadcaster br;
tf::Transform transform;
//geometry_msgs::Quaternion qw;
tf::Quaternion q;
//定义初始坐标和角度
double roll = 0, pitch = 0, yaw = 0, x = 1.0, y = 2.0, z = 3.0;

ros::Rate rate(1);
while(ros::ok())
{
yaw += 0.1;//每经过1s开始一次变换
//输入欧拉角,转换成四元数并在终端进行输出
q.setRPY(roll, pitch, yaw);

transform.setOrigin(tf::Vector3(x, y, z));
transform.setRotation(q);

cout<<"发布tf变换:sendTransform函数"<<endl;
br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", "link1"));
cout<<"输出的四元数为:w="<<q[3]<<", x="<<q[0]<<", y= "<<q[1]<<",z="<<q[2]<<endl;
rate.sleep();
ros::spinOnce();
}
return 0;
}
