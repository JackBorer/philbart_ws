#ifndef NRG_SL_DATA_TEST_NODE_H
#define NRG_SL_DATA_TEST_NODE_H

#include <ros/ros.h>

#include <vector>
#include <string>




class NRGSLdata_testNODE{
    ros::NodeHandle nh_;
    ros::Publisher pub_wind_;
    ros::Publisher pub_gas_;

    std::vector< std::vector<double> > measurement_data;
public:
    NRGSLdata_testNODE();
    void setMeasurementData( std::string path );
    void pubMeasurement();

};
#endif //NRG_SL_DATA_TEST_NODE_H