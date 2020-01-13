//https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val)
                nums[ans++] = nums[i];
        }
        
        return ans;
    }
};

//More Efficient Solution in a particular case
//when elements to be removed are rare
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, n=nums.size();
        
        while(i<n){
            if(nums[i]==val){
                nums[i] = nums[n-1]; //order of elements can be changed
                n--;
            }
            else
                i++;
        }
        
        return i;
    }
};