#ifndef NRG_SL_DATA_TEST_NODE_H
#define NRG_SL_DATA_TEST_NODE_H

#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>

#include <vector>
#include <string>


/*
* Use this node to record bag files of simulated data
* Or dont record bag file and just run this node everytime you want to publish the topics
*/

class NRGSLdata_testNODE{
    ros::NodeHandle nh_;
    ros::Publisher pub_wind_;
    ros::Publisher pub_gas_;
    tf2_ros::TransformBroadcaster pub_tf_;

    std::vector< std::vector<double> > simulation_data;
public:
    NRGSLdata_testNODE();
    int getSimulationDataSize() const;
    void setSimulationData( std::string path );
    void pubMeasurement();

};
#endif //NRG_SL_DATA_TEST_NODE_H