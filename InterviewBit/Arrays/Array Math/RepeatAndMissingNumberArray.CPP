//https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long sum=0, sqsum=0;
    long long a, b;
    for(int i=0,j=1; i<A.size(); i++, j++){
        sum+=j;
        sum-=A[i];
        sqsum+=(long long)j*j;
        sqsum-=(long long)A[i]*A[i];
    }
    b = (sum + sqsum/sum)/2;
    a = b - sum;
    vector<int> ans{a,b};
    return ans;
}

