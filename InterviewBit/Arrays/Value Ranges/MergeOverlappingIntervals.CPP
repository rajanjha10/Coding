/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp(const Interval &a, const Interval &b){
    return a.start<b.start;    
} 

vector<Interval> Solution::merge(vector<Interval> &A) {
    int i;
    vector<Interval> ans;
    sort(A.begin(), A.end(), comp);
    ans.push_back(A[0]);
    for(i=1; i<A.size(); i++){
        if(ans.back().end>=A[i].start){
            ans.back().end = max(ans.back().end, A[i].end);
            ans.back().start = min(ans.back().start, A[i].start);
        }
        else
            ans.push_back(A[i]);
    }
    return ans;
}
