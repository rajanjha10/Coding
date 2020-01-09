//https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber(const vector<int> &A) {
    int i;
    int first = INT_MAX, second = INT_MAX;
    int cntf=0, cnts=0;
    for(i=0; i<A.size(); i++){
        if(A[i]==first)
            cntf++;
        else if(A[i]==second)
            cnts++;
        else if(cntf==0){
            cntf=1;
            first = A[i];
        }
        else if(cnts==0){
            cnts=1;
            second = A[i];
        }
        else{
            cntf--;
            cnts--;
        }
    }
    cntf = cnts=0;
    for(i=0; i<A.size(); i++){
        if(A[i]==first)
            cntf++;
        else if(A[i]==second)
            cnts++;
    }
    if(cntf>A.size()/3)
        return first;
    if(cnts>A.size()/3)
        return second;
    return -1;
}

//Probability Solution
int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int ans,flag=0;
    for(int i=0;i<23;i++){
        int index=rand()%n;
        int elem=A[index];
        int count=0;
        for(int i=0;i<n;i++){
            if(A[i]==elem)
            count++;
        }
        if(count>n/3){
            flag=1;
            ans=elem;
        }
        if(flag==1)
        break;
    }

    if(flag==1)
        return ans;
    return -1;
}
