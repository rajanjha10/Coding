//https://www.interviewbit.com/problems/max-distance/

//O(n)
int Solution::maximumGap(const vector<int> &A) {
    vector<int> minA(A.size()), maxA(A.size());
    int i, j=0, ans=0;
    minA[0] = A[0]; maxA[A.size()-1] = A[A.size()-1];
    for(i=A.size()-2; i>=0; i--)
        maxA[i] = max(A[i], maxA[i+1]);
    for(i=1; i<A.size(); i++)
        minA[i] = min(A[i], minA[i-1]);
    i=0;
    while(i<minA.size() && j<maxA.size()){
        if(minA[i] <= maxA[j]){
            ans = max(ans, j-i);
            j++;
        }
        else
            i++;
    }
    return ans;
}

//O(nlogn)
int Solution::maximumGap(const vector<int> &A) {
    vector<int> B(A.size());
    int ans = 0, i;
    for(i=0; i<A.size(); i++)
        B[i] = i;
    sort(B.begin(), B.end(), [&A](const int &a,const int &b){
        return A[a] < A[b];
    });
    for(i=B.size()-2; i>=0; i--){
        int m = max(B[i], B[i+1]);
        ans = max(ans, m - B[i]);
        B[i] = m;
    }
    return ans;
}
