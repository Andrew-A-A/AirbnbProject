cmake_minimum_required(VERSION 3.22)
project(AirbnbProject)

set(CMAKE_CXX_STANDARD 14)

include_directories("classes")

add_executable(AirbnbProject
        "classes/Host.cpp"
        "classes/Host.h"
        "classes/HostsPlaces.cpp"
        "classes/HostsPlaces.h"
        "Main.cpp"
        "classes/NewUser.cpp"
        "classes/NewUser.h"
        "classes/Travelers.cpp"
        "classes/Travelers.h"
        "classes/TravelerTrips.cpp"
        "classes/TravelerTrips.h" classes/Admin.cpp classes/Admin.h DataStructure/Stack.cpp DataStructure/Stack.h DataStructure/Queue.cpp DataStructure/Queue.h)
