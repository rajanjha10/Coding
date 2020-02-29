//https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int ans=INT_MIN;
        while(left<right){
            ans = max(ans, min(height[left], height[right])*(right-left));
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};