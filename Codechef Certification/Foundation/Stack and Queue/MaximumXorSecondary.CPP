//https://codeforces.com/contest/281/problem/D

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
    int n;
    cin>>n;
    LL max_xor = INT_MIN, a;
    stack<LL> st;
    for(int i=0; i<n; i++){
    	cin>>a;
    	while(!st.empty()){
    		max_xor = max(max_xor, a^st.top());
    		if(st.top()>a)
    			break;
    		st.pop();
    	}
    	st.push(a);
    }
    
    cout<<max_xor<<endl;

    return 0;    
}