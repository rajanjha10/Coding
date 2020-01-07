//https://www.interviewbit.com/problems/maxspprod/

int Solution::maxSpecialProduct(vector<int> &A) {
    vector<int> leftmax(A.size());
    vector<int> rightmax(A.size());
    long long ans = 0, m = 1000000007;
    int i;
    leftmax[0] = rightmax[A.size()-1] = 0;
    stack<pair<int, int> > l, r;
    l.push({A[0], 0});
    for(i=1; i<A.size(); i++){
        while(!l.empty() && l.top().first<=A[i])
            l.pop();
        if(l.empty())
            leftmax[i]=0;
        else
            leftmax[i] = l.top().second;
        l.push({A[i], i});
    }
    r.push({A[A.size()-1], A.size()-1});
    for(i=A.size()-2; i>=0; i--){
        while(!r.empty() && r.top().first<=A[i])
            r.pop();
        if(r.empty())
            rightmax[i] = 0;
        else
            rightmax[i] = r.top().second;
        r.push({A[i], i});
    }
    for(i=1; i<A.size()-1; i++)
        ans = max(ans, (leftmax[i] * (1LL) * rightmax[i]));
    return (int)(ans%m);
}
