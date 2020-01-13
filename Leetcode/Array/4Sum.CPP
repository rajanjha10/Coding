//https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)
            return {};
        
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            for(int j=i+1; j<nums.size()-2; j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                
                int start = j+1;
                int end = nums.size()-1;
                
                while(start<end){
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    
                    if(sum==target){
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while(start<end && nums[start]==nums[start+1])
                            start++;
                        while(start<end && nums[end]==nums[end-1])
                            end--;
                        start++;
                        end--;
                    }
                    else if(sum>target)
                        end--;
                    else
                        start++;
                }
            }
        }
        
        return ans;
    }
};

//Using set to eliminate duplicates
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4)
            return {};
        set<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; i++){
            for(int j=i+1; j<nums.size()-2; j++){
                int start = j+1;
                int end = nums.size()-1;
                
                while(start<end){
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    
                    if(sum==target){
                        ans.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                    }
                    else if(sum>target)
                        end--;
                    else
                        start++;
                }
            }
        }
        
        return vector<vector<int> > (ans.begin(), ans.end());
    }
};