//https://www.interviewbit.com/problems/maximum-unsorted-subarray/

vector<int> Solution::subUnsort(vector<int> &A) {
    int l=-1, r=-1, i, temp;
    temp=A[0];
    for(i=1; i<A.size(); i++){
        if(A[i]<temp) r=i;
        temp = max(temp, A[i]);
    }
    temp = A[A.size()-1];
    for(i=A.size()-2; i>=0; i--){
        if(A[i]>temp) l=i;
        temp = min(temp, A[i]);
    }
    if(l==-1) return {-1};
    return {l, r};
}
