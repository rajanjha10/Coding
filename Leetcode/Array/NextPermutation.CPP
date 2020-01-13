//https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-1; i>0; i--){
            if(nums[i]>nums[i-1])
                break;
        }
        
        if(i==0)
            sort(nums.begin(), nums.end());
        else{    
            int swapIndex=i-1;
            int minIndex = swapIndex+1; 
            for(i=swapIndex+2; i<nums.size(); i++){
                if(nums[i]>nums[swapIndex] && nums[i]<nums[minIndex])
                    minIndex = i;
            }

            swap(nums[minIndex], nums[swapIndex]);

            sort(nums.begin()+swapIndex+1, nums.end());
        }
    }
};