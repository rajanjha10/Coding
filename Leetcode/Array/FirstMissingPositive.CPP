//https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        while(i<=j){
            if(nums[i]>0)
                i++;
            else{
                swap(nums[i], nums[j]);
                j--;
            }
        }
        
        i=0;
        j++;
        while(i<j){
            if(abs(nums[i])<=j && nums[abs(nums[i])-1]>0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            i++;
        }
        
        for(i=0; i<j; i++)
            if(nums[i]>0)
                return i+1;
        
        return i+1;
    }
};

//Another Space Recycle Approach
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && nums[i]<=nums.size()){
                if(nums[i]!=nums[nums[i]-1]){
                    swap(nums[i], nums[nums[i]-1]);
                    i--;
                }
            }
        }
        for(int i=0; i<nums.size(); i++)
            if(nums[i]!=i+1)
                return i+1;
        
        return nums.size()+1;
    }
};