#include<ros/ros.h>
#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
    ros::init(argc, argv, "param1");
    ros::NodeHandle nh;

    int parameter1, parameter2, parameter3, parameter4, parameter5;

    //获取param的三种方法
    //1.ros::param::get()获取参数"param1"的value，写入parameter1上
    bool ifget1 = ros::param::get("param1", parameter1);
    //2.ros::NodeHandle::getParam()获取参数，与1作用相同
    bool ifget2 = nh.getParam("param2", parameter2);
    //3.ros::NodeHandle::param()，它可以给param指定一个默认值
    nh.param("param3", parameter3, 123); //123默认值
    if(ifget1)//parameter1是否取得
             cout<<parameter1<<endl;
   if(ifget2)//parameter2是否取得
             cout<<parameter2<<endl;
   cout<<parameter3<<endl;
    //1.Set Param
    parameter4 = 4;

    ros::param::set("param4", parameter4);
cout<<parameter4<<endl;
    //2.ros::NodeHandle::setParam() set param
       parameter5 = 5;
    nh.setParam("param5", parameter5);
cout<<parameter5<<endl;
    //Check Param
    //1.ros::NodeHandle::hasParam()
    bool ifparam5 = nh.hasParam("param5");
if(ifparam5)//parameter2是否取得
             cout<<"has param5"<<endl;
else
	cout<<"doesn't have param5"<<endl;
    //2.ros::param::has()
    bool ifparam6 = ros::param::has("param6");
if(ifparam6)//parameter2是否取得
             cout<<"has param6"<<endl;
else
	cout<<"doesn't have param6"<<endl;
    //Delete param
    //1.ros::NodeHandle::deleteParam()
    bool ifdeleted5 = nh.deleteParam("param5");
if(ifdeleted5)//parameter2是否取得
             cout<<"delete param5"<<endl;
else
	cout<<"doesn't delete param5"<<endl;
    //2.ros::param::del()
    bool ifdeleted6 = ros::param::del("param6");
if(ifdeleted6)//parameter2是否取得
             cout<<"delete param6"<<endl;
else
	cout<<"doesn't delete param6"<<endl;





}
