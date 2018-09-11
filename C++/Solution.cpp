#include "Solution.hpp"

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	bool start_is_in = false;
	int start_index = -1;
	bool end_is_in = false;
	int end_index = intervals.size();
	for (int i = 0; i < intervals.size(); ++i) {
		if (newInterval.start > intervals[intervals.size() - 1].end) {
			start_index = intervals.size();
			start_is_in = false;
		}
		if (newInterval.start < intervals[i].start) {
			if (start_index == -1) {
				start_index = i - 1;
				start_is_in = false;
			}
        }
		else if (newInterval.start >= intervals[i].start && newInterval.start <= intervals[i].end) {
			if (start_index == -1) {
				start_index = i;
				start_is_in = true;
			}
		}
		if (newInterval.end < intervals[0].start) {
			end_index = -1;
			end_is_in = false;
		}
		if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end) {
			end_index = i;
			end_is_in = true;
		}
		else if (newInterval.end > intervals[i].end) {
			end_index = i + 1;
			end_is_in = false;
		}
    }
	while (start_index + 1 < end_index){
		intervals.erase(intervals.begin() + start_index + 1);
		end_index--;
	}
	if (start_is_in == false && end_is_in == false) {
		if (start_index == -1) {
			intervals.insert(intervals.begin(), newInterval);
		}
		else intervals.insert(intervals.begin() + start_index + 1, newInterval);
	}
	else if (start_is_in == true && end_is_in == false) {
		intervals[start_index].end = newInterval.end;
	}
	else if (start_is_in == false && end_is_in == true) {
		intervals[end_index].start = newInterval.start;
	}
	else {
		intervals[start_index].end = intervals[end_index].end;
		intervals.erase(intervals.begin() + end_index);
	}
	return intervals;
}
