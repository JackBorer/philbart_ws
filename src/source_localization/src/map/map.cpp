#include "../include/map/map.h"

boost::shared_ptr<map_t> load_map_t(const nav_msgs::OccupancyGrid& data)
{
    boost::shared_ptr<map_t> map(new map_t());

    map->width = 5.0;
    //map->height =
    //map->map =

    return map;
}