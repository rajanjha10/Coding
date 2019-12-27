//https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int ans=0, i;
    int curx = A[0], cury = B[0];
    for(i=1; i<A.size(); i++){
        ans+= max(abs(A[i]-curx), abs(B[i]-cury));
        curx = A[i], cury = B[i];
    }
    return ans;
}
