//http://codeforces.com/contest/343/problem/B

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0; i<s.size(); i++){
    	if(st.empty() || st.top()!=s[i])
    		st.push(s[i]);
    	else
    		st.pop(); 
    }
    
    if(st.size())
    	cout<<"No"<<endl;
    else
    	cout<<"Yes"<<endl;

    return 0;    
}