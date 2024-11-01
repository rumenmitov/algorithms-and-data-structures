#pragma once

#include <chrono>
#include <time.h>
#include <list>

struct Activity {
    int id;
    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::time_point<std::chrono::steady_clock> end;
};


/**
 * @brief Returns the latest starting activity.
 * 
 * @param std::list<Activity>&
 * 
 * @return Activity
*/
Activity get_latest_starting_activity(std::list<Activity>&);


/**
 * @brief Provides solution for the activity-selection problem.
 * 
 * @param std::list<Activity>&
 * 
 * @return std::list<Activity>
*/
std::list<Activity> activity_solution(std::list<Activity>&);

