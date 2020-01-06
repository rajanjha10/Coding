//https://www.interviewbit.com/problems/largest-number/

bool comp(string a, string b){
    return a+b > b+a;
}

string Solution::largestNumber(const vector<int> &A) {
    string ans = "";
    vector<string> B(A.size());
    for(int i=0; i<A.size(); i++)
        B[i] = to_string(A[i]);
    sort(B.begin(), B.end(), comp);
    if(B[0]=="0")
        return "0";
    for(int i=0; i<B.size(); i++)
        ans+= B[i];
    return ans;
}
