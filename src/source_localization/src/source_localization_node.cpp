/*Author Jack Borer July 2020
//Build Command: catkin build source_localization --cmake-args -DCMAKE_BUILD_TYPE=Debug 
*/

/*Big Picture Questions
// Do I need std::mutex functionality
// How do shared pointers interact with ros::spin?
*/

/*TO DO July 13 2020
// Fill out pf.h function declarations 
// Build pf.cpp (pf_alloc, pf_init etc)
// Remove pf_vector.h include because it will come with pf.h
// Uncomment the model selection section now that we have the param server with defaults up
*/

/*
// To watch smart pointer value in debug: <smart_ptr_obj>._M_ptr
*/


//Standard library
#include "iostream"
#include "memory" //smart pointers

//roscpp
#include "ros/ros.h"

//Required ROS msgs and srvs
#include "std_msgs/String.h"
#include "nav_msgs/OccupancyGrid.h" // Can I remove this becasue it is decalred in map.h?
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float32.h"
#include "nav_msgs/GetMap.h"

//Custom includes
#include "../include/map/map.h"
#include "../include/pf/pf.h"



// Maybe once we import the header files this error will do away
// using namespace sl; 

//Pose hypothesis
static const std::string node_name_ = "sl";

static const std::string map_topic_ = "map";
static const std::string odom_topic_ = "odometry/filtered_map";
static const std::string anemometer_topic_ = "anemometer/data";
static const std::string gas_sensor_topic_ = "gas_sensor/data";

class SLNode
{
    public:
      SLNode();
      ~SLNode() {};

    private:  
      void handleMapMessage(const nav_msgs::OccupancyGrid& msg);
      void mapReceived(const nav_msgs::OccupancyGridConstPtr& msg);
      void requestMap();


      // Particle filter
      std::shared_ptr<pf_t> pf_;
      int min_particles_, max_particles_;
      bool pf_init_;

      std::string base_frame_id_;
      std::string global_frame_id_; 

     std::shared_ptr<map_t> map_;

      bool use_map_topic_;
      bool first_map_only_;
      bool first_map_received_;
      bool map_received_; 

      std::string transport_model_type_;

      ros::NodeHandle nh_;
      ros::NodeHandle private_nh_;
      ros::Subscriber map_sub_;
      ros::Subscriber map_pose_sub_;
      ros::Subscriber anemometer_sub_;
      ros::Subscriber gas_sensor_sub_;
      
      void mapOdomCB(const nav_msgs::Odometry& msg);
      void anemometerCB(const geometry_msgs::Twist& msg);
      void gasSensorCB(const std_msgs::Float32& msg);
  
};

std::shared_ptr<SLNode> sl_node_ptr;

int main(int argc, char** argv)
{
  ros::init(argc, argv, node_name_);
  ros::NodeHandle nh;

  sl_node_ptr.reset(new SLNode());
  
  //Run using ROS, may add .bag file functionality later
  if (1)
  {
    ros::spin();
  }

  return(0);
}

SLNode::SLNode() :
        //map_(NULL),
        first_map_received_(false)
{
  // Get all parameters off of the parameter server
  // Think about using a private nodehandle for some reason?
  private_nh_.param("use_map_topic", use_map_topic_, true);
  private_nh_.param("base_frame_id", base_frame_id_, std::string("base_link"));
  private_nh_.param("global_frame_id", global_frame_id_, std::string("map"));
  private_nh_.param("min_particles", min_particles_, 100);
  private_nh_.param("max_particles", max_particles_, 5000);

  /*
  // Uncomment this module when the parameter server has been brought online
  //Future proofing the node for adding transport models later
  std::string tmp_model_type;
  private_nh_.param("transport_model_type", tmp_model_type, std::string("gaussian_plume"));
  if(tmp_model_type == "gaussian_plume")
  {
    transport_model_type_ = "GAUSSIAN_PLUME";
  }else
  {
    ROS_WARN("Unknown transport model type \"%s\"; defaulting to gaussian_plume model", tmp_model_type.c_str());
    transport_model_type_ = "GAUSSIAN_PLUME";
  }
  */
  if(use_map_topic_){ //line 490
    map_sub_ = nh_.subscribe(map_topic_, 1, &SLNode::mapReceived, this);
    ROS_INFO("Subscribed to map topic.");
  }else{
    requestMap();
  }

  map_pose_sub_ = nh_.subscribe(odom_topic_, 2, &SLNode::mapOdomCB, this);
  anemometer_sub_ = nh_.subscribe(anemometer_topic_, 2, &SLNode::anemometerCB, this);
  gas_sensor_sub_ = nh_.subscribe(gas_sensor_topic_, 2, &SLNode::gasSensorCB, this);

}

void 
SLNode::mapOdomCB(const nav_msgs::Odometry& msg)
{

}

void 
SLNode::anemometerCB(const geometry_msgs::Twist& msg)
{

}

void 
SLNode::gasSensorCB(const std_msgs::Float32& msg)
{

}

//Descrip
void 
SLNode::requestMap()
{
  // Service request for a static map from the map server
  nav_msgs::GetMap::Request req;
  // Service response hopefully containing the static map from the map server
  nav_msgs::GetMap::Response resp;
  ROS_INFO("Requesting the map...");
  while(!ros::service::call("static_map", req, resp))
  {
    ROS_WARN("Request for map failed; trying again...");
    ros::Duration d(0.5);
    d.sleep();
  }

  handleMapMessage(resp.map);
}

// The callback for the map subscription 
void 
SLNode::mapReceived(const nav_msgs::OccupancyGridConstPtr& msg)
{
  if(first_map_only_ && first_map_received_) 
  {
    return;
  }

  handleMapMessage(*msg);

  first_map_received_ = true;
}

//Descrip
void
SLNode::handleMapMessage(const nav_msgs::OccupancyGrid& msg)
{
  ROS_INFO("Received a %d X %d map @ %.3f m/pix\n",
           msg.info.width,
           msg.info.height,
           msg.info.resolution);
  
  if(msg.header.frame_id != global_frame_id_)
    ROS_WARN("Frame_id of map received:'%s' doesn't match global_frame_id:'%s'. This could cause issues with reading published topics",
             msg.header.frame_id.c_str(),
             global_frame_id_.c_str());

  //freeMapDependentMemory();
  
  map_ = load_map_t(msg);


  // Create the particle filter
  pf_ = pf_alloc(min_particles_, max_particles_);
  
  
  // How to access state of set 1
  // std::cout<< pf_->sets[0]->samples[2000].state.v[0]  <<std::endl;

  // Initialize the filter
  pf_init(pf_, map_);
  pf_init_ = false;
  

  // Instantiate the sensor objects
  // Odometry
  // Laser
  
  // In case the initial pose message arrived before the first map,
  // try to apply the initial pose now that the map has arrived.


}

