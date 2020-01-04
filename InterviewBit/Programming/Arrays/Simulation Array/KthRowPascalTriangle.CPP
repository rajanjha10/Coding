//https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int A) {
    vector<int> ans;
    int n=1;
    for(int i=0; i<=A; i++){
        ans.push_back(n);
        n = n*(A-i)/(i+1);
    }
    return ans;
}
