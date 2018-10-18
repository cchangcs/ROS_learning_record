#include<ros/time.h>
#include<ros/duration.h>
#include<ros/ros.h>
#include<iostream>
using namespace std;
int main(int argc, char** argv){
ros::init(argc, argv, "time_d");
ros::Time::init();
ros::Time begin = ros::Time::now();//获取当前时间
cout<< "begin: "<< begin <<endl;
ros::Time at_some_time1(5, 20000000);//5.2s
cout<< "at_some_time1: " <<at_some_time1 <<endl;
ros::Time at_some_time2(5.2);//5.2s
cout<< "at_some_time2: " << at_some_time2 <<endl;
ros::Duration one_hour(60 * 60, 0);//1h
cout<< "one_hour: " << one_hour <<endl;

double secs1 = at_some_time1.toSec();//将Time转换为double型时间
cout<<"secs1: " << secs1 <<endl;
double secs2 = one_hour.toSec();//将Duration转换为double型时间
cout<< "secs2: " <<secs2 <<endl;
//Time指的是某个时刻,Duration指的是某个时间段
ros::Time t1 = ros::Time::now() - ros::Duration(5.5);//t1是5.5s前的时刻,Time减去Duration返回的是Time
cout<<"t1: " << t1 <<endl;
ros::Time t2 = ros::Time::now() + ros::Duration(3.3);//t2是3.3s后的时刻
cout<<"t2: " << t2 <<endl;
ros::Duration d1 = t2 - t1;//从t1到t2的时长,两个Time相减返回Duration类型
cout<<"d1: " <<d1 <<endl;
ros::Duration d2 = d1 - ros::Duration(0, 300);//两个Duration相减,返回的是Duration
cout<< "d2: " <<d2 <<endl;
ros::spin();
return 0;
}
