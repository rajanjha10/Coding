//https://leetcode.com/problems/trapping-rain-water/

//Stack Approach
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        
        int n = height.size(), curr=0, ans=0;
        stack<int> index;
        while(curr<n){
            while(!index.empty() && height[curr]>height[index.top()]){
                int top = index.top();
                index.pop();
                if(index.empty())
                    break;
                int distance = curr - index.top() - 1;
                int bounded_height = min(height[curr], height[index.top()]) - height[top];
                ans+= distance*bounded_height;
            }
            index.push(curr++);
        }
        return ans;
    }
};

//Two Pointer Approach
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        
        int ans=0;
        int left = 0, right = height.size()-1;
        int left_max=0, right_max=0;
        while(left<right){
            if(height[left]<height[right]){
                if(height[left] > left_max)
                    left_max = height[left];
                else
                    ans += left_max - height[left];
                left++;
            }
            else{
                if(height[right] > right_max)
                    right_max = height[right];
                else
                    ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};

//Dynamic Programming Approach
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        
        int n = height.size();
        vector<int> lmax(n), rmax(n);
        lmax[0] = height[0];
        rmax[n-1] = height[n-1];
        for(int i=1; i<height.size(); i++)
            lmax[i] = max(lmax[i-1], height[i]);
        for(int i=n-2; i>=0; i--)
            rmax[i] = max(rmax[i+1], height[i]);
        
        int ans = 0;
        for(int i=0; i<height.size(); i++)
            ans+= min(lmax[i], rmax[i]) - height[i];
        
        return ans;
    }
};

//Reduced Space Complexity of DP Approach
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        
        int n = height.size(), maxIndex=0, ans=0;
        vector<int> maxHeight(n);
        for(int i=0; i<height.size(); i++){
            if(height[i]>height[maxIndex])
                maxIndex = i;
        }
        maxHeight[0] = height[0];
        maxHeight[n-1] = height[n-1];
        for(int i=1; i<maxIndex; i++)
            maxHeight[i] = max(maxHeight[i-1], height[i]);
        for(int i=n-2; i>=maxIndex; i--)
            maxHeight[i] = max(maxHeight[i+1], height[i]);
        
        for(int i=0; i<n; i++)
            ans+= maxHeight[i] - height[i];
        
        return ans;
    }
};