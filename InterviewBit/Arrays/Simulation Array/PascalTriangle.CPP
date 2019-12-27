//https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    if(A==0)
        return {};
    vector<vector<int> > ans(A);
    ans[0].push_back(1);
    for(int i=1; i<A; i++){
        ans[i].push_back(1);
        for(int j=1; j<i; j++){
            ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
        ans[i].push_back(1);
    }
    
    return ans;
}
