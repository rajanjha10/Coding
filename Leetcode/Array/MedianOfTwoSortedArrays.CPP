//https://leetcode.com/problems/median-of-two-sorted-arrays/

//Binary search - O(log(min(n, m)))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int x = nums1.size(), y=nums2.size();
        int low = 0, high = x;
        
        while(low<=high){
            int partitionX = (low+high)/2;
            int partitionY = (x+y+1)/2 - partitionX;
            
            int maxLeftX = partitionX==0? INT_MIN : nums1[partitionX-1];
            int maxLeftY = partitionY==0? INT_MIN : nums2[partitionY-1];
            
            int minRightX = partitionX==x? INT_MAX : nums1[partitionX];
            int minRightY = partitionY==y? INT_MAX : nums2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((x+y)%2==0)
                    return ((max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0);
                else
                    return max(maxLeftX, maxLeftY);
            }
            
            if(maxLeftX > minRightY)
                high = partitionX-1;
            else
                low = partitionX+1;
        }
        
        return 0;
    }
};

//merge technique of merge sort - O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int index1=0, index2=0, size = (nums1.size()+nums2.size())/2;
        while(index1!=nums1.size() || index2!=nums2.size()){
            if(index1==nums1.size())
                merge.push_back(nums2[index2++]);
            else if(index2==nums2.size())
                merge.push_back(nums1[index1++]);
            else{
                if(nums1[index1]<nums2[index2])
                    merge.push_back(nums1[index1++]);
                else
                    merge.push_back(nums2[index2++]);
            }
            if(merge.size()-1==size)
                break;
        }
        
        float ans = merge[merge.size()-1];
        if((nums1.size()+nums2.size())%2==0){
            ans+=merge[merge.size()-2];
            ans/=2.0;
        }
        return ans;
    }
};