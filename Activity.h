//
// Created by alexh on 11/7/2024.
//

#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <chrono>
#include <string>


class Activity {
private:
    int id;
    std::string name;
    double distance;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;


};



#endif //ACTIVITY_H
