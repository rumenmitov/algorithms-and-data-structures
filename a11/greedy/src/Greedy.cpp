#include "Greedy.h"


Activity get_latest_starting_activity(std::list<Activity>& l) {
    Activity latest = l.front();
    auto it_pos_latest = l.begin();

    for (auto it = l.begin(); it != l.end(); it++) {
      if (it->start > latest.start) {
	latest = *it;
	it_pos_latest = it;
      }
    }

    l.erase(it_pos_latest);
    return latest;
}


std::list<Activity> activity_solution(std::list<Activity>& l) {
  std::list<Activity> solution;
  
  while (!l.empty()) {
    Activity latest = get_latest_starting_activity(l);

    if (solution.empty()) {
      solution.push_back(latest);
      continue;
    }

    if (solution.back().start > latest.end) solution.push_back(latest);
  }

  return solution;
}
