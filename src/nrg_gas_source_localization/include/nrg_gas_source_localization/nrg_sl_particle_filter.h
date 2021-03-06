#ifndef NRG_SL_PARTICLE_FILTER_H
#define NRG_SL_PARTICLE_FILTER_H

#include "vector"

struct pf_params{
    int np; 
    int np_min;
    //Measurement noise
    double R;
    //Resampling noise
    double Q;
};

/**
* @note The state we are predicting is the location and emission rate of a fugitive gas emission source (x,y,z,q)
*
* @brief Each particle represents a weighted state hypothesis 
* @param double downwind_conc The concentration produced at some location by the source represented by the particle 
* @param double position[3] The global location of the source
* @param double rate The emission rate of the source 
*/
struct particle{
    particle()
    : weight{},
      downwind_conc{},
      position(3),
      rate{}
    {}
    
    //Fraction of the probability distribution
    double weight;
    //Concentration produced by the particle at some downwind test point
    double downwind_conc;
    //The state which we are trying to predict is the combination of position and rate
    std::vector<double> position;
    double rate;
};

/**
* @brief The state and statistical characterization of the filter
* @param std::vector<particle> particles The particle set the filter use to represent the probability distribution of the state
* @param int np The number of particles 
* @param double R The measurement model noise
* @param double Q The resampling noise introduced to prevent single particle state collapse when resampling
*/
struct particle_set{
    std::vector<particle> particles; //TODO think about typedef
};

struct state_space{
    state_space()
    :x(2),
     y(2),
     z(2),
     rate(2)
    {}

    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;
    std::vector<double> rate;
};

struct wind_model{
    wind_model()
    :sy(3),
     sz(3)
    {}

    std::vector<double> sy;
    std::vector<double> sz;
};

struct measurement
{
    double az;
    double vel; //TODO change to speed 
    double conc;
    int time_stamp;
    std::vector<double> location;
};

class ParticleFilter{
    /**
    * @brief Initialize an already paramaterized filter's particle set
    * @param int The number of particles to generate
    * @return void
    */
    void initialize(); // Change Neff and R to params

    /**
    * @brief Calculate the theoretical concentration at the measurement location from each particle
    * @param measurement 
    * @return void
    */
    void theoretical_concentration( measurement );  

    /**
    * @brief Update the filter's particle set weights
    * @param measurement 
    * @return void
    */
    void reweight( measurement ); 

    /**
    * @brief If Neff<Neff_lim then resample to prevent degeneracy
    * @return void
    */
    void resample(); 

    /**
    * @brief Check if the particle set is degenerate
    * @return bool True if the particle set is degenerate and Neff< Neff_lim
    */
    bool isDegenerate() const; //TODO make name more descriptive about return condition

    void printMeasurement( measurement ) const;
    
    pf_params pfp_;
    state_space ss_;
    wind_model wm_;

    bool initialized;
    particle_set ps;
    
public:
    /**
    * @brief Construct an unparameterized filter
    * @return ParticleFilter
    */
    ParticleFilter(); 
    
    /**
    * @brief Construct a parameterized filter
    * @param pf_params Particle filter parameterization
    * @param state_space The state space bounds
    * @param wind_model The wind model parameters
    * @return ParticleFilter 
    */
    ParticleFilter(pf_params, state_space, wind_model); 
    
    /**
    * @brief Initialize an unparameterized filter
    * @param int The number of particles to generates
    * @param state_space The filter's state space
    * @param wind_model The filter's gaussian plume wind model dispersion parameters
    * @return void
    */
    void initialize(pf_params, state_space, wind_model);

    /**
    * @brief Call predict, reweight, and resample to process a measuremnt and update the filter
    * @param measurement A new measuremnt 
    * @return void
    
    */
    void updateFilter(measurement); 

    /**
    * @brief Print the filter's particle set mean
    * @return void
    */
    void printStatistics() const;
};

#endif