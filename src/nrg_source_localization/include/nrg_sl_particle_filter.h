#ifndef NRG_SL_PARTICLE_FILTER_H
#define NRG_SL_PARTICLE_FILTER_H

#include "vector"

struct particle{
    //Fraction of the probability distribution
    double weight;
    //Concentration produced by the particle at some downwind test point
    double downwind_conc;
    //The state which we are trying to predict is the combination of position and rate
    double position[3];
    double rate;
};
struct particle_set{
    std::vector<particle> particles;
    int np;

    // Number of "effective" particles
    double Neff_lim;
    // Measurement noise
    double R;
    // Resampling noise
    double Q;
};
struct state_space{
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    state_space():x{0.0, 0.0}, y{0.0, 0.0}, z{0.0, 0.0}, rate{0.0, 0.0} {};

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    state_space(double x_min, double x_max, double y_min, double y_max, double z_min, double z_max, double rate_min, double rate_max)
        :x{x_min, x_max}, y{y_min, y_max}, z{z_min, z_max}, rate{rate_min, rate_max}
        {};

    double x[2];
    double y[2];
    double z[2];
    double rate[2];
};
struct wind_model{
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    wind_model(): sy{0, 0, 0}, sz{0, 0, 0} {};

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    wind_model(double sya, double syb, double syc, double sza, double szb, double szc)
        :sy{sya,syb,syc},sz{sza,szb,szc}
        {};

    double sy[3];
    double sz[3];
};
struct measurement
{
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    measurement(): az{0}, vel{0}, conc{0}, time_stamp{0} {};

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    measurement(double azimuth, double velocity, double concentration, int time_stamp)
        : az{azimuth}, vel{velocity}, conc{concentration}, time_stamp{time_stamp}
        {};

    double location[3];
    double az;
    double vel;
    double conc;
    int time_stamp;
};


class ParticleFilter{
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void initialize(int); // Change Neff and R to params

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void predict(measurement);  //DONE

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void reweight(measurement); //DONE

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void resample(); //DONE

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    bool ifNeff() const;

    particle_set ps;
    state_space ss_;
    wind_model wm_;

    bool initialized;
    
public:
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    ParticleFilter(); //DONE 
    
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    ParticleFilter(int, state_space, wind_model); //DONE 
    
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void initialize(int, state_space, wind_model); // Change Neff and R to params 

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void updateFilter(measurement); 

    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void printStatistics() const;
    
    
};

//utils
namespace pf{
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    std::vector<double> uniform_rn(int count);
    
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    double uniform_rn();
    
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    void transform(double*, const double*, const double*, const double&);
    
    /**
    * @brief 
    * @param 
    * @param 
    * @return 
    */
    double gaussian(double, double, double);
} //END of pf namespace

#endif