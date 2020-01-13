//https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> ss;
        sort(candidates.begin(), candidates.end());
        find_sets(candidates, ans, ss, target, 0);
        return ans;
    }
    
    void find_sets(vector<int> &candidates, vector<vector<int> > &ans, vector<int> &ss, int sum, int i){
        if(sum<0)
            return;
        if(sum==0){
            ans.push_back(ss);
            return;
        }
        while(i<candidates.size() && sum-candidates[i]>=0){
            ss.push_back(candidates[i]);
            find_sets(candidates, ans, ss, sum-candidates[i], i+1);
            ss.pop_back();
            while(i+1<candidates.size() && candidates[i+1]==candidates[i])
                i++;
            i++;
        }
    }
};

//Recursive Approach
void find_sets(vector<int> &candidates, vector<vector<int> > &ans, vector<int> &ss, int sum, int i){
    if(sum==0){
        ans.push_back(ss);
        return;
    }
    if(sum<0 || i>=candidates.size())
        return;
    ss.push_back(candidates[i]);
    find_sets(candidates, ans, ss, sum-candidates[i], i+1);
    ss.pop_back();
    while(i+1<candidates.size() && candidates[i+1]==candidates[i])
        i++;
    find_sets(candidates, ans, ss, sum, i+1);
}

