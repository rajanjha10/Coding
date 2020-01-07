//https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &A) {
    int dindex=0, n=A.size(), i;
    for(i=n-1; i>=0; i--){
        if(A[i-1]<A[i]){
            dindex = i;
            break;
        }
    }
    if(i==0){
        sort(A.begin(), A.end());
        return A;
    }
    int sindex=dindex;
    for(i=dindex+1; i<n; i++){
        if(A[i]>A[dindex-1] && A[i]<A[sindex])
            sindex = i;
    }
    
    swap(A[dindex-1], A[sindex]);
    
    sort(A.begin()+dindex, A.end());
    
    return A;
}