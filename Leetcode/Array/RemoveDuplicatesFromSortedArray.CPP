//https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        int ans=1;
        for(int i=0; i<nums.size()-1; i++)
            if(nums[i+1]>nums[i])
                nums[ans++]=nums[i+1];
            
        
        return ans;
    }
};