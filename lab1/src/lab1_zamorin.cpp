#include "ros/ros.h"
#include <iostream>
#include "std_msgs/Int32.h"
#include "std_msgs/Int8.h"
using namespace std;

ros::Publisher temperature_f_pub;

void callback(const std_msgs::Int8& temp_c)
{
    ROS_INFO("Tempreture Celsius: %d", temp_c.data);
	
    std_msgs::Int32 temp_f;
    temp_f.data = (temp_c.data * 9) / 5 + 32;
	
    ROS_INFO("Tempreture Fahrenheit: %d", temp_f.data);
    temperature_f_pub.publish(temp_f);
	
    return;
}     
                                                                                                                           
int main(int argc, char **argv)
{
    ROS_INFO("Start lab_1_zamorin package");
    
    ros::init(argc, argv, "temperature");
    ros::NodeHandle n;

    ros::Subscriber temperature_f_sub = n.subscribe("/temperature_c", 10, callback);
    temperature_f_pub = n.advertise<std_msgs::Int32>("/temperature_f", 10);

    ros::spin();
	
    return 0;
}
