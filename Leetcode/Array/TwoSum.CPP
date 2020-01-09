//https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;
        for(int i=0; i<nums.size(); i++){
            if(a.find(target-nums[i])!=a.end())
                return {a[target-nums[i]], i};
            a[nums[i]]=i;
        }
        return {};
    }
};
