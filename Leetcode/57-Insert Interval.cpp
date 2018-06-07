
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int length = intervals.size();
		int start = newInterval.start;
		int end = newInterval.end;
        
        int index = 0;
        vector<Interval> result;
        while(index<length && intervals[index].end<start)
        {
            result.push_back(intervals[index]);
            index++;
        };
        while(index<length && intervals[index].start<=end)
        {
            newInterval = Interval(
                min(newInterval.start,intervals[index].start),
                max(newInterval.end,intervals[index].end)
            );
            index++;
        }
        result.push_back(newInterval);
        
        while(index<length)
        {
            result.push_back(intervals[index]);
            index++;
        }

		return result;
	}
}; 

