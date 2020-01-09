//https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    int i, fl=-1, fr=-1, l=0;
    long long cmx=0, mx=0;
    for(i=0; i<A.size(); i++){
        if(A[i]<0){
            cmx=0;
            l = i+1;
            continue;
        }
        cmx+=A[i];
        if(cmx>mx){
            mx = cmx;
            fl = l;
            fr = i;
        }
        else if(cmx==mx && i-l>fr-fl){
            fl = l;
            fr = i;
        }
    }
    if(fl==-1)
        return {};
    else{
        vector<int> ans;
        ans.assign(A.begin()+fl, A.begin()+fr+1);
        return ans;
    }
        
}
