//https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

int Solution::maxSubArray(const vector<int> &A) {
    int mx=A[0], curmx=A[0];
    for(int i=1; i<A.size(); i++){
        curmx = max(A[i], curmx+A[i]);
        mx = max(mx, curmx);
    }
    return mx;
}
