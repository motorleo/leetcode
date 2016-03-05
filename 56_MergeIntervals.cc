/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct cmp
{
	bool operator()(const Interval& lhs,const Interval& rhs)
	{
		return lhs.start < rhs.start;
	}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		if (intervals.empty()) return result;
		sort(intervals.begin(),intervals.end(),cmp());
		int currentStart = intervals[0].start;
		int currentEnd = intervals[0].end;
		for (int i = 1;i < intervals.size();++i)
		{
			if (currentEnd >= intervals[i].start)
			{
				currentEnd = max(intervals[i].end,currentEnd);
			}
			else
			{
				result.push_back(Interval(currentStart,currentEnd));
				currentStart = intervals[i].start;
				currentEnd = intervals[i].end;
			}
		}
		result.push_back(Interval(currentStart,currentEnd));
		return result;
    }
};
