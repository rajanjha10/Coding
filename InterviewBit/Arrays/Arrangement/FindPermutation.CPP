//https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    if(B==0)
        return {};
    int cntD=0, i;
    vector<int> ans;
    for(int i=0; i<A.size(); i++)
        if(A[i]=='D')
            cntD++;

    int fd=1+cntD, fi=1+fd;
    ans.push_back(fd--);
    for(i=0; i<A.size(); i++){
        if(A[i]=='I')
            ans.push_back(fi++);
        else
            ans.push_back(fd--);
    }
    return ans;
}
