cmake_minimum_required(VERSION 3.22)
project(AirbnbProject)

set(CMAKE_CXX_STANDARD 14)

include_directories("classes")

add_executable(AirbnbProject
        "classes/AirbnbHosts.cpp"
        "classes/AirbnbHosts.h"
        "classes/AirbnbPlaces.cpp"
        "classes/AirbnbPlaces.h"
        "classes/HostsPlaces.cpp"
        "classes/HostsPlaces.h"
        "Main.cpp"
        "classes/NewUser.cpp"
        "classes/NewUser.h"
        "classes/Travelers.cpp"
        "classes/Travelers.h"
        "classes/TravelerTrips.cpp"
        "classes/TravelerTrips.h")
