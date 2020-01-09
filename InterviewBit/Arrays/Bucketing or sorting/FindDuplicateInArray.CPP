//https://www.interviewbit.com/problems/find-duplicate-in-array/

int Solution::repeatedNumber(const vector<int> &A) {
    int sq = sqrt(A.size()), i;
    int range = (A.size()/sq)+1;
    int cnt[range];
    memset(cnt, 0, sizeof(cnt));
    for(i=0; i<A.size(); i++){
        cnt[(A[i]-1)/sq]++;
    }
    int s = range-1;
    for(i=0; i<range-1; i++){
        if(cnt[i]>sq){
            s = i;
            break;
        }
    }
    unordered_map<int, int> a;
    for(i=0; i<A.size(); i++){
        if(A[i]>(s*sq) && A[i]<=((s+1)*sq))
        {
            a[A[i]]++;
            if(a[A[i]]>1)
                return A[i];
        }
    }
    
    return -1;
}

//top solution
int Solution::repeatedNumber(const vector<int> &A) {
    int slow = A[0], fast = A[A[0]];
    
    while(slow != fast){
        slow = A[slow];
        fast = A[A[fast]];
    }
    fast = 0;
    while(fast != slow){
        fast = A[fast];
        slow = A[slow];
    }
    return slow;
}
