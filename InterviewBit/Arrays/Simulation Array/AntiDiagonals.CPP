//https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector<vector<int> > ans(2*A.size()-1);
    int i, j, k;
    for(i=0; i<A.size(); i++){
        k=i;
        for(j=0; j<A[0].size(); j++){
            ans[k].push_back(A[i][j]);
            k++;
        }
    }
    return ans;
}
