//https://www.interviewbit.com/problems/maximum-absolute-difference/

int Solution::maxArr(vector<int> &A) {
    int i, ans;
    int maxadd = INT_MIN, maxsub = INT_MIN;
    int minadd = INT_MAX, minsub = INT_MAX;
    
    for(i=0; i<A.size(); i++){
        maxadd = max(maxadd, A[i]+i);
        minadd = min(minadd, A[i]+i);
        maxsub = max(maxsub, A[i]-i);
        minsub = min(minsub, A[i]-i);
    }
    ans = max(maxadd-minadd, maxsub-minsub);
    return ans;
}
