cmake_minimum_required(VERSION 2.8.3)
project(philbart_localization)

find_package(catkin REQUIRED COMPONENTS roslaunch)

catkin_package()

roslaunch_add_file_check(launch)

install(DIRECTORY config launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

catkin_install_python(PROGRAMS src/localization_transition.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)