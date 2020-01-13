//https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
        
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int r = 0, c=0;
        
        while(r<n && c<m){
            for(int i=c; i<m; i++)
                ans.push_back(matrix[r][i]);
            r++;
            
            for(int i=r; i<n; i++)
                ans.push_back(matrix[i][m-1]);
            m--;
            
            if(r<n){
                for(int i=m-1; i>=c; i--)
                    ans.push_back(matrix[n-1][i]);
                n--;
            }
            
            if(c<m){
                for(int i=n-1; i>=r; i--)
                    ans.push_back(matrix[i][c]);
                c++;
            }
        }
        
        return ans;
    }
};