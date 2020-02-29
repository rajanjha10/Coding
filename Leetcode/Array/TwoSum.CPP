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

//Using Unordered Map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> a;
        for(int i=0; i<nums.size(); i++){
            if(a[target-nums[i]]>0)
                return {a[target-nums[i]]-1, i};
            a[nums[i]]=i+1;
        }
        return {};
    }
};
