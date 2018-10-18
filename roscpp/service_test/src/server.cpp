#include <ros/ros.h>
#include <service_test/Greeting.h>

bool handle_function(service_test::Greeting::Request &req, service_test::Greeting::Response &res){
    //显示请求信息
    ROS_INFO("Request from %s with age %d", req.name.c_str(), req.age);
    //处理请求，结果写入response
    res.feedback = "Hi " + req.name + ". I'm server!";
    //返回true，正确处理了请求
    return true;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "greetings_server");        //解析参数，命名节点
    ros::NodeHandle nh;                       //创建句柄，实例化node
    ros::ServiceServer service = nh.advertiseService("greetings", handle_function);  //写明服务的处理函数
    ros::spin();
    return 0;
}
