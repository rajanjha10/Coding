//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curmax = nums[0];
        int maximum = nums[0];
        for(int i=1; i<nums.size(); i++){
            curmax = max(curmax+nums[i], nums[i]);
            maximum = max(maximum, curmax);
        }
        
        return maximum;
    }
};

//Divide and Conquer Approach - O(nlogn)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divide_and_conquer(nums, 0, nums.size()-1);
    }
    
    int divide_and_conquer(vector<int>& nums, int low, int high){
        if(low==high)
            return nums[low];
        int mid = (low+high)/2;
        
        int mx =  max(divide_and_conquer(nums, low,  mid),
                      divide_and_conquer(nums, mid+1, high));
        return max(mx, max_overlap(nums, low, mid, high));
    }
    
    int max_overlap(vector<int>& nums, int low, int mid, int high){
        int leftMax, rightMax, sum=0;
        leftMax = rightMax = INT_MIN;
        
        for(int i=mid; i>=low; i--){
            sum+=nums[i];
            leftMax = max(leftMax, sum);
        }
        sum=0;
        for(int i=mid+1; i<=high; i++){
            sum+=nums[i];
            rightMax = max(rightMax, sum);
        }
        
        return leftMax+rightMax;
    }
};