//https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &A) {
    int i, j;
    bool r=0, c=0;
    for(i=0; i<A[0].size(); i++)
        if(A[0][i]==0){
            r=1;
            break;
        }
        
    for(i=0; i<A.size(); i++)
        if(A[i][0]==0){
            c=1;
            break;
        }
        
    for(i=0; i<A.size(); i++){
        for(j=0; j<A[0].size(); j++){
            if(A[i][j]==0){
                A[i][0] = A[0][j] = 0;
            }
        }
    }
    
    for(i=1; i<A.size(); i++){
        for(j=1; j<A[0].size(); j++){
            if(A[i][0]==0 || A[0][j]==0)
                A[i][j]=0;
        }
    }
    
    if(r){
        for(i=0; i<A[0].size(); i++)
            A[0][i]=0;
    }        
    if(c){
        for(i=0; i<A.size(); i++)
            A[i][0]=0;
    }
}
