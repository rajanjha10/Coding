//https://leetcode.com/problems/3sum/

//Time-100ms memory-14.5MB
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) 
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for(int i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum==0){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    while(start<end && nums[start]==nums[start+1])
                        start++;
                    while(start<end && nums[end]==nums[end-1])
                        end--;
                    start++;
                    end--;
                }
                else if(sum>0)
                    end--;
                else
                    start++;
            }
        }
        
        return ans;
    }
};

//Eliminating duplicates using set (Time-832ms memory-121MB)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3) 
            return {};
        sort(nums.begin(), nums.end());
        set<vector<int> > ans;
        for(int i=0; i<nums.size()-2; i++){
            int start = i+1;
            int end = nums.size()-1;
            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum==0){
                    ans.insert({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                }
                else if(sum>0)
                    end--;
                else
                    start++;
            }
        }
        
        return vector<vector<int> > (ans.begin(), ans.end());
    }
};