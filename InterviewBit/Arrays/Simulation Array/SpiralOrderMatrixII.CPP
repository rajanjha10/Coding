//https://www.interviewbit.com/problems/spiral-order-matrix-ii/

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > ans(A, vector<int>(A));
    int i, r = 0, c=0, n=A, m=A, cnt=1;
    while(r<n && c<m){
        for(i=c; i<m; i++)
            ans[r][i] = cnt++;
        r++;
        
        for(i=r; i<n; i++)
            ans[i][m-1] = cnt++;
        m--;
        
        if(r<n){
            for(i=m-1; i>=c; i--)
                ans[n-1][i] = cnt++;
            n--;
        }
        
        if(c<m){
            for(i=n-1; i>=r; i--)
                ans[i][c] = cnt++;
            c++;
        }
    }
    return ans;
}
