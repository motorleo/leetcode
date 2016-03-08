/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		int currentStart = newInterval.start;
		int currentend = newInterval.end;
		bool MergeFlag = true;
		for (int i = 0;i < intervals.size();++i)
		{
			if (intervals[i].end < currentStart)
			{
				result.push_back(intervals[i]);
			}
			else if (intervals[i].start > currentend)
			{
				if (MergeFlag)
				{
					result.push_back(Interval(currentStart,currentend));
					MergeFlag = false;
				}
				result.push_back(intervals[i]);
			}
			else
			{
				currentStart = min(intervals[i].start,currentStart);
				currentend = max(currentend,intervals[i].end);
			}
		}
		if (MergeFlag)
			result.push_back(Interval(currentStart,currentend));
		return result;
	}
};
