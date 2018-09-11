#include <vector>
#include <iostream>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

#include <map>
using namespace std;

class Solution {
public:
	struct numbers {
		bool left;
		bool right;
		numbers() : left(0), right(0) {}
	};
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.size() == 0) {
			intervals.push_back(newInterval);
			return intervals;
		}
		int singular_num = INT_MIN;
		if (newInterval.start == newInterval.end) singular_num = newInterval.start;
		vector<int> edge;
		map<int, numbers> relation;
		for (int i = 0; i < intervals.size(); ++i) {
			if (intervals[i].start != intervals[i].end) {
				edge.push_back(intervals[i].start);
				relation[intervals[i].start].right = 1;
				edge.push_back(intervals[i].end);
				relation[intervals[i].end].left = 1;
			}
			else {
				edge.push_back(intervals[i].start);
				relation[intervals[i].start].left = 0;
			}
		}

		if (singular_num == INT_MIN) {
			if (relation[newInterval.start].left == 0 && relation[newInterval.start].right == 0) {
				for (int i = 0; i < edge.size(); ++i) {
					if (newInterval.start < edge[i]) {
						edge.insert(edge.begin() + i, newInterval.start);
						break;
					}
					else if (newInterval.start == edge[i]) break;
					else if (i == edge.size() - 1) {
						edge.insert(edge.end(), newInterval.start);
						break;
					}
				}
			}
			relation[newInterval.start].right = 1;

			if (relation[newInterval.end].left == 0 && relation[newInterval.end].right == 0) {
				for (int i = 0; i < edge.size(); ++i) {
					if (newInterval.end < edge[i]) {
						edge.insert(edge.begin() + i, newInterval.end);
						break;
					}
					else if (newInterval.end == edge[i]) break;
					else if (i == edge.size() - 1) {
						edge.insert(edge.end(), newInterval.end);
						break;
					}
				}
			}
			relation[newInterval.end].left = 1;
		}
		else {
			if (relation[newInterval.start].left == 0 && relation[newInterval.start].right == 0) {
				for (int i = 0; i < edge.size(); ++i) {
					if (newInterval.start < edge[i]) {
						edge.insert(edge.begin() + i, newInterval.start);
						break;
					}
					else if (newInterval.end == edge[i]) break;
					else if (i == edge.size() - 1) {
						edge.insert(edge.end(), newInterval.start);
						break;
					}
				}
			}
		}

		intervals.insert(intervals.begin(), newInterval);
		for (int x = 0; x < intervals.size(); ++x) {
			bool flag = 0;
			for (int i = 0; i < edge.size(); ++i) {
				if (intervals[x].start == intervals[x].end) continue;
				if (edge[i] == intervals[x].start) flag = 1;
				else if (edge[i] == intervals[x].end) break;

				if (flag) {
					if (edge[i] != intervals[x].start && edge[i] != intervals[x].end) {
						relation[edge[i]].left = 1;
						relation[edge[i]].right = 1;
					}
				}
			}
		}

		intervals.clear();
		Interval tmp;
		for (int i = 0; i < edge.size(); ++i) {
			if (relation[edge[i]].left == 0 && relation[edge[i]].right == 0) {
				intervals.push_back(Interval(edge[i], edge[i]));
			}
			else if (relation[edge[i]].left == 0) {
				tmp.start = edge[i];
			}
			else if (relation[edge[i]].left == 1 && relation[edge[i]].right == 1)
				continue;
			else if (relation[edge[i]].right == 0) {
				tmp.end = edge[i];
				intervals.push_back(tmp);
			}
		}
		return intervals;
	}
};

int main() {
	vector<Interval> intervals;
	intervals.push_back(Interval(0, 0));
	intervals.push_back(Interval(1, 4));
	intervals.push_back(Interval(6, 7));
	intervals.push_back(Interval(9, 11));
	Interval newinterval = Interval(0, 0);
	Solution so;
	vector<Interval> ret = so.insert(intervals, newinterval);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i].start << ' ' << ret[i].end << endl;
	}
	return 0;
}