//https://leetcode.com/problems/jump-game/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        while(i+nums[i]<nums.size()-1){
            int maxVal = 0;
            int maxIndex = -1;
            for(int j=1; j<=nums[i]; j++){
                if(j+nums[i+j]>maxVal){
                    maxVal = j+nums[i+j];
                    maxIndex = i+j;
                }
            }
            if(maxIndex==-1)
                return false;
            i=maxIndex;
        }
        
        return true;
    }
};

//Another Greedy Approach
//Will not be able to give min number of jumps
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int leftGoodIndex = nums.size()-1;
        for(int i=nums.size()-2; i>=0; i--){
            if(i+nums[i]>=leftGoodIndex)
                leftGoodIndex = i;
        }
        
        return leftGoodIndex==0 ? true : false;
    }
};

//BFS Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<int> currLevel;
        currLevel.push(0);
        int leftBound=0, rightBound;
        while(!currLevel.empty()){
            rightBound = leftBound;
            while(!currLevel.empty()){
                int index = currLevel.front();
                currLevel.pop();
                if(index==nums.size()-1)
                    return true;
                rightBound = max(rightBound, index+nums[index]);
            }
            for(int i=leftBound+1; i<=rightBound && i<nums.size(); i++)
                currLevel.push(i);
            leftBound = rightBound; 
        }
        
        return false;
    }
};

//DP Approach - O(n2)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> jumps(nums.size(), INT_MAX);
        jumps[0] = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size() && j<=i+nums[i]; j++)
                if(jumps[i]!=INT_MAX)
                    jumps[j] = min(jumps[j], jumps[i]+1);
        }
        
        return jumps[nums.size()-1]==INT_MAX ? false : true;
    }
};