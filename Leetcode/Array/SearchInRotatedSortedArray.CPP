//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        
        int pivot = binary_search_pivot(nums);
        
        auto s1 = lower_bound(nums.begin(), nums.begin()+pivot, target);
        auto s2 = lower_bound(nums.begin()+pivot+1, nums.end(), target);
        
        if(s1!=nums.begin()+pivot+1 && *s1==target)
            return s1 - nums.begin();
        if(s2!=nums.end() && *s2==target)
            return s2 - nums.begin();
        return -1;
    }
    
    int binary_search_pivot(vector<int>& nums){
        int low = 0, high = nums.size()-1;
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[low] && nums[mid]>nums[high])
                low = mid;
            else
                high = mid;
        }
        
        return low;
    }
};