//
// Created by alexh on 11/10/2024.
//

#include "ActivityStorage.h"

void ActivityStorage::addActivity(Activity activity) {
    activities[activity.getId()] = activity;
}

Activity ActivityStorage::getActivityById(int id) {
    return activities[id];
}

Activity ActivityStorage::getMostRecentActivity() {
    // placeholder for now
    return activities.rbegin()->second;
}
