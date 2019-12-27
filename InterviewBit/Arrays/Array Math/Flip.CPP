//https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    int mx=0, cmx=0, l=0, fl=-1, fr=-1;
    int i;
    for(i=0; i<A.size(); i++){
        if(A[i]=='1')
            cmx--;
        else
            cmx++;
        if(cmx<0){
            cmx=0;
            l=i+1;
        }
        else if(cmx>mx){
            mx = cmx;
            fl = l;
            fr = i;
        }
    }
    if(fl==-1)
        return {};
    else
        return {fl+1, fr+1};
}
