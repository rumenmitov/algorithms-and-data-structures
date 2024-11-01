
#ifdef DEBUG

#include <cassert>
#include <chrono>
#include <iostream>
#include <unordered_set>

#include "Greedy.h"

using namespace std;
using namespace chrono;

#endif

int main(int argc, char* argv[]) {

  #ifdef DEBUG

    cout << "Testing get_latest_starting_activity...";

    list<Activity> l;

    Activity solution;
    solution.id = 0;
    solution.start = time_point<steady_clock>( seconds(1000) );
    solution.end = time_point<steady_clock>( seconds(1001) );

    for (int i = 0; i < 10; i++) {
        time_point<steady_clock> start( (seconds(i)) );
        time_point<steady_clock> end( seconds(i+1) );

        Activity rand_activity;
        rand_activity.id = i + 1;
        rand_activity.start = start;
        rand_activity.end = end;

        l.push_back(rand_activity);
    }

    l.push_back(solution);

    assert( solution.id == get_latest_starting_activity(l).id );

    cout << "passed." << endl;

    cout << "Testing greedy solution to the activity problem...";

    std::list<Activity> solution_final;
    std::list<Activity> activities;

    Activity a1;
    a1.id = 1;
    a1.start = time_point<steady_clock>( seconds(5) );
    a1.end = time_point<steady_clock>( seconds(10) );

    solution_final.push_back(a1);
    activities.push_back(a1);

    Activity a2;
    a2.id = 2;
    a2.start = time_point<steady_clock>( seconds(0) );
    a2.end = time_point<steady_clock>( seconds(3) );

    solution_final.push_back(a2);
    activities.push_back(a2);

    Activity a3;
    a3.id = 3;
    a3.start = time_point<steady_clock>( seconds(2) );
    a3.end = time_point<steady_clock>( seconds(6) );

    activities.push_back(a3);

    auto result = activity_solution(activities);

    assert (solution_final.size() == result.size());

    std::unordered_set<int> solution_activity_ids;
    std::unordered_set<int> result_ids;
    

    for (auto a : solution_final) solution_activity_ids.insert(a.id);
    for (auto a : result) result_ids.insert(a.id);

    for (auto id : solution_activity_ids) {
      assert( result_ids.count(id) == 1 );
    }

    cout << "passed\n";

#endif

    return 0;
}


