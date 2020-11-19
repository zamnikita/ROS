#include "ros/ros.h"
#include "lab2_zamorin/GetDescription.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main(int argc, char **argv)
{
	
	ros::init(argc, argv, "standart_model_client");
	ros::NodeHandle n;
	ros::ServiceClient lab2_client = n.serviceClient<lab2_zamorin::GetDescription>("get_description_client");
	lab2_zamorin::GetDescription srv;
	ros::Rate loop_rate(1);
	srand(static_cast<unsigned int>(time(0)));

	while(ros::ok()) 
	{
		int row1, col1;
		row1 = rand() % 4 + 1;
		col1 = rand() % 5 + 1; 

		ROS_INFO_STREAM("Elementary Particle row = " << row1 << ", column = " << col1);
		srv.request.row = row1;
		srv.request.column = col1;
		

		if(lab2_client.call(srv))
		{
			ROS_INFO_STREAM(srv.response.answer);
		}		
		else
		{
			ROS_ERROR_STREAM("Failed to get description of Elementary Particle");
		}
		loop_rate.sleep();
	}
	return 0;
}
