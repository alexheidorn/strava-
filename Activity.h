//
// Created by saga on 11/7/2024.
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
        int movingTime;
        int elapsedTime;
        std::string type; // ride, run, etc.
        std::string sportType; // Mountain Bike, Trail Run, etc.
        std::string workoutType; // race, commute, workout, etc.
        std::chrono::system_clock::time_point startTime;
        std::chrono::system_clock::time_point endTime;

        // /* OPTIONAL PARAMS FOR LATER */
        // / startDateLocal;
        // / avgCadence
        // / avgWatts
        // / avgHR
        // / maxHR
        // / maxSpeed

    public:




};



#endif //ACTIVITY_H
