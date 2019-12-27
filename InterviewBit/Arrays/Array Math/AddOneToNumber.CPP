//https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    int i, c=1;
    for(i=A.size()-1; i>=0; i--){
        if(A[i]+c>9){
            c = A[i]+c-9;
            A[i]=0;
        }
        else{
            A[i]=A[i]+c;
            c = 0;
            break;
        }
    }
    if(c!=0)
        A.insert(A.begin()+i+1, c);
    while(A.front()==0){
        A.erase(A.begin());
    }
    return A;        
}
