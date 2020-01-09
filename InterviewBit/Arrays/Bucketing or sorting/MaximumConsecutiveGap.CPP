//https://www.interviewbit.com/problems/maximum-consecutive-gap/

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<=1)
        return 0;
    int mx=INT_MIN, ans=INT_MIN, i, mn=INT_MAX;
    for(i=0; i<A.size(); i++){
        mx = max(A[i], mx);
        mn = min(A[i], mn);
    }
    
    int gap = (mx+mn-1)/(A.size()-1) + 1;
    vector<pair<int, int> > bucket(A.size()-1, {INT_MIN+1, INT_MAX-1});
    
    for(i=0; i<A.size(); i++){
        if(A[i]!=mn && A[i]!=mx){
            int index = (A[i]-mn)/gap;
            bucket[index].first = max(bucket[index].first, A[i]);
            bucket[index].second = min(bucket[index].second, A[i]);
        }
    }
    int prevm = mn;
    for(i=0; i<bucket.size()-1; i++){
        if(bucket[i].second==INT_MAX-1)
            continue;
        ans = max(ans, bucket[i].second - prevm);
        prevm = bucket[i].first;
    }
    ans = max(ans, mx - prevm);
    return ans;
}