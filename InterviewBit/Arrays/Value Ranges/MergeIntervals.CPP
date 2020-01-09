//https://www.interviewbit.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int i;
    if(newInterval.start>newInterval.end)
        swap(newInterval.start, newInterval.end);
    vector<Interval> ans;
    for(i=0; i<intervals.size(); i++){
        if(intervals[i].end >= newInterval.start){
            intervals.insert(intervals.begin()+i, newInterval);
            break;
        }
    }
    if(i==intervals.size())
        intervals.push_back(newInterval);
    ans.push_back(intervals[0]);
    for(i=1; i<intervals.size(); i++){
        if(ans.back().end >= intervals[i].start){
            ans.back().end = max(intervals[i].end, ans.back().end);
            ans.back().start = min(intervals[i].start, ans.back().start);
        }
        else
            ans.push_back(intervals[i]);
    }
    return ans;
}
