//
// Created by alexh on 11/10/2024.
//

#ifndef ACTIVITYSTORAGE_H
#define ACTIVITYSTORAGE_H
#include <map>

#include "Activity.h"


class ActivityStorage {
    private:
        std::map<int, Activity> activities;

    public:
        void addActivity(Activity activity);
        Activity getActivityById(int id);
        Activity getLastActivity();

};



#endif //ACTIVITYSTORAGE_H
