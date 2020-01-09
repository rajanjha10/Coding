//https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A) {
    int i;
    for(i=0; i<A.size(); i++){
        if(A[i]>0 && A[i]<=A.size()){
            if(A[i]!=A[A[i]-1]){
                swap(A[i], A[A[i]-1]);
                i--;
            }
        }
    }
    for(i=0; i<A.size(); i++)
        if(A[i]!=(i+1))
            return i+1;
    return i+1;
}
