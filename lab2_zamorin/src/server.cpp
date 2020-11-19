#include "ros/ros.h"
#include "lab2_zamorin/GetDescription.h"
#include "../include/standart_model_description.h"
#include <iostream>

using namespace std;

bool get_description(lab2_zamorin::GetDescription::Request &req, lab2_zamorin::GetDescription::Response &res)
{
	
	if (((req.row > 4) && (req.column > 5)) || ((req.row > 1) && (req.column > 4)) || (req.row < 1) || (req.column < 1))   {
		ROS_INFO_STREAM("no element");
		res.answer = "no element";
	}
	else 
	{
		element req_element;
		req_element = standart_model_description[req.row-1][req.column-1];
		res.answer = "Name - " + req_element.name + ", type - " + req_element.type + ", mass = " + 
		req_element.mass + ", charge = " + req_element.charge + ", spin = " + req_element.spin;
		ROS_INFO_STREAM(res.answer);
	}
	return true;
}

int main(int argc, char **argv)
{
	
	ros::init(argc, argv, "standart_model_server");
	ros::NodeHandle n;
	
	ros::ServiceServer lab2_service = n.advertiseService("get_description",get_description);
	
	ROS_INFO("Ready to give description of Elementary Particle");
	ros::spin();
	return 0;
}


