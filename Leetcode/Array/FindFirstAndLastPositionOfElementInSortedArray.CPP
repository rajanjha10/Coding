//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1, -1};
        
        int first, last;
        
        first = binary_lower(nums, target);
        last = binary_upper(nums, target) - 1;
        if(nums[first]==target && nums[last]==target)
            return {first, last};
        else
            return {-1, -1};
    }
    
    int binary_lower(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]>=target)
                high = mid;    
            else
                low = mid+1;
        }
        
        return low;
    }
    
    int binary_upper(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size();
        
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]>target)
                high = mid;
            else
                low = mid+1;
        }
        
        return low;
    }
};

//merging both binary search into one
int binary_bounds(vector<int>& nums, int target, bool lower){
    int low = 0;
    int high = nums.size();
    if(lower)
        high--;
    
    while(low<high){
        int mid = (low+high)/2;
        if(nums[mid]>target || (lower && nums[mid]==target))
            high = mid;
        else
            low = mid+1;
    }
    
    return low;
}

//using STL C++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first, last;
        
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(it==nums.end() || *it!=target)
            return {-1, -1};
        first = it - nums.begin();
        it = upper_bound(nums.begin(), nums.end(), target);
        last = it - nums.begin() - 1;
        return {first, last};
    }
};