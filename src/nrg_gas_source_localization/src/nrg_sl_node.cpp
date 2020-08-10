#include <nrg_sl_node.h>

#include <iostream>

NRGSLNode::NRGSLNode()
: nh_(), 
  private_nh_("~")
{
  pf_params _pfp;
  private_nh_.param( "number_of_particles", 
                     _pfp.np,
                     1000 );
  private_nh_.param( "minimum_number_of_particles",
                     _pfp.np_min,
                     500 );
  private_nh_.param( "measurement_noise", 
                     _pfp.R,
                     1.0 );
  private_nh_.param( "resampling_noise",
                     _pfp.Q,
                     0.1);

  state_space _ss;
  private_nh_.getParam( "x_bounds",
                        _ss.x );
  private_nh_.getParam( "y_bounds", 
                        _ss.y );
  private_nh_.getParam( "z_bounds", 
                        _ss.z );
  private_nh_.getParam( "rate_bounds", 
                        _ss.rate );

  wind_model _wm;
  private_nh_.getParam( "wind_model_horizontal_dispersion", 
                        _wm.sy );
  private_nh_.getParam( "wind_model_vertical_dispersion", 
                        _wm.sz );

  filter_.initialize(_pfp, _ss, _wm);

  sub1.subscribe( nh_, 
                  "/anemometer_data_topic", 
                  10 );
  sub2.subscribe( nh_, 
                  "/gas_sensor_data_topic", 
                  10 );

  sync.reset(new Sync(MySyncPolicy(10), sub1, sub2));   
  sync->registerCallback(boost::bind(&NRGSLNode::callback, this, _1, _2));
}

void NRGSLNode::callback(const AnemometerMsgConstPtr &in1, const MG811MsgConstPtr &in2)
{
} 







////////////////Entry Point/////////////////
int main(int argc, char** argv)
{
  ros::init(argc, argv, "nrg_source_localization_node");
  NRGSLNode synchronizer;

  ros::spin();
  
  return(0);
}