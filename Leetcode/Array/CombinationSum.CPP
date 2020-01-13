//https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> ss;
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        find_sets(candidates, target, ans, ss, 0);
        return ans;
    }
    
    void find_sets(vector<int>& candidates, int sum, vector<vector<int> >& ans, vector<int> ss, int i){
        if(sum<0)
            return;
        if(sum==0){
            ans.push_back(ss);
            return;
        }
        while(i<candidates.size() && sum-candidates[i]>=0){
            ss.push_back(candidates[i]);
            find_sets(candidates, sum-candidates[i], ans, ss, i);
            ss.pop_back();
            i++;
        }
    }
};

//Recursive approach
void find_sets(vector<int>& candidates, int sum, vector<vector<int> >& ans, vector<int> ss, int i){
    if(sum<0 || i>=candidates.size())
        return;
    if(sum==0){
        ans.push_back(ss);
        return;
    }
    ss.push_back(candidates[i]);
    find_sets(candidates, sum-candidates[i], ans, ss, i);
    ss.pop_back();
    find_sets(candidates, sum, ans, ss, i+1);
}