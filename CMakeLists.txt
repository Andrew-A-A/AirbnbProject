cmake_minimum_required(VERSION 3.22)
project(AirbnbProject)

set(CMAKE_CXX_STANDARD 14)

include_directories("File Reading")

add_executable(AirbnbProject
        "File Reading/AirbnbHosts.cpp"
        "File Reading/AirbnbHosts.h"
        "File Reading/AirbnbPlaces.cpp"
        "File Reading/AirbnbPlaces.h"
        "File Reading/HostsPlaces.cpp"
        "File Reading/HostsPlaces.h"
        "File Reading/Main.cpp"
        "File Reading/NewUser.cpp"
        "File Reading/NewUser.h"
        "File Reading/Travelers.cpp"
        "File Reading/Travelers.h"
        "File Reading/TravelerTrips.cpp"
        "File Reading/TravelerTrips.h")
