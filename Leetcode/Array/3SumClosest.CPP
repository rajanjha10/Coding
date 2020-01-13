//https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX - abs(target);
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int start = i+1;
            int end = nums.size()-1;
            
            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(abs(target-ans)>abs(target-sum))
                    ans = sum;
                if(ans==target)
                    return ans;
                if(sum>target)
                    end--;
                else
                    start++;
            }
        }
        
        return ans;
    }
};