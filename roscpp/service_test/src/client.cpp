# include <ros/ros.h>
# include <service_test/Greeting.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "greetings_client");// 初始化，节点命名为"greetings_client"
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<service_test::Greeting>("greetings");
    // 定义service客户端，service名字为“greetings”，service类型为Service_demo

    // 实例化srv，设置其request消息的内容，这里request包含两个变量，name和age，见Greeting.srv
    service_test::Greeting srv;
    srv.request.name = "HAN";
    srv.request.age = 20;

    if (client.call(srv))
    {
        // 注意我们的response部分中的内容只包含一个变量response，另，注意将其转变成字符串
        ROS_INFO("Response from server: %s", srv.response.feedback.c_str());
    }
    else
    {
        ROS_ERROR("Failed to call service Service_demo");
        return 1;
    }
    return 0;
}
