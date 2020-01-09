//https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int m = A[0].size(), n = A.size();
    vector<int> ans;
    int r = 0, c = 0;
    while(r<n && c<m){
        for(int i=c; i<m; i++)
            ans.push_back(A[r][i]);
        r++;
        
        for(int i=r; i<n; i++)
            ans.push_back(A[i][m-1]);
        m--;
        
        if(r<n){
            for(int i=m-1; i>=c; i--)
                ans.push_back(A[n-1][i]);
            n--;
        }
        if(c<m){
            for(int i=n-1; i>=r; i--)
                ans.push_back(A[i][c]);
            c++;
        }
    }
    return ans;
}
