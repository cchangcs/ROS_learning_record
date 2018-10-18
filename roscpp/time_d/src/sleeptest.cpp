#include<ros/duration.h>
#include<ros/rate.h>
#include<ros/ros.h>
#include<iostream>
using namespace std;

int main(int argc, char** argv){
ros::init(argc, argv, "sleeptest");
ros::Time::init();
ros::Time begin = ros::Time::now();
cout<<"begin: "<<begin<<endl;
ros::Duration(10).sleep();//用Duration对象的sleep方法休眠
ros::Time begin2 = ros::Time::now();
cout<<"begin2: "<<begin2<<endl;
ros::Rate r(10);//10HZ
while(ros::ok())
{
r.sleep();
ros::Time begin3 = ros::Time::now();
cout<<"begin: "<<begin3<<endl;
}
ros::spin();
return 0;
}
