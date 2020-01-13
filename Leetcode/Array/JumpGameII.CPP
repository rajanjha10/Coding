//https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int jumps = 0, i=0;
        while(i+nums[i]<nums.size()-1){
            int maxVal = 0;
            int maxIndex;
            for(int j=1; j<=nums[i]; j++){
                if(j+nums[i+j] > maxVal){
                    maxVal = j+nums[i+j];
                    maxIndex = i+j;
                }
            }
            i=maxIndex;
            jumps++;
        }
        
        return jumps+1;
    }
};

//BFS Approach - O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        queue<int> currLevel;
        currLevel.push(0);
        int leftBound=0, rightBound, level=0;
        
        while(!currLevel.empty()){
            rightBound = leftBound;
            while(!currLevel.empty()){
                int index = currLevel.front();
                currLevel.pop();
                if(index==nums.size()-1)
                    return level;
                rightBound = max(rightBound, index+nums[index]);
            }
            for(int i=leftBound+1; i<=rightBound && i<nums.size(); i++)
                currLevel.push(i);
            level+=1;
            leftBound=rightBound;
        }
        
        return -1;
    }
};

//DP Approach - O(n2)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jumps_cnt(nums.size(), INT_MAX);
        jumps_cnt[0] = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<=i+nums[i] && j<nums.size(); j++)
                jumps_cnt[j] = min(jumps_cnt[j], jumps_cnt[i]+1);
        }
        return jumps_cnt[nums.size()-1];
    }
};
