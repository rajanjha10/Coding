//https://codeforces.com/contest/797/problem/C

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
    string s, u="";
    cin>>s;
    stack<char> t;
    int n = s.size();
    char least[n];
    least[n-1] = s[n-1];
    for(int i=n-2; i>=0; i--)
    	least[i] = min(least[i+1], s[i]);
    for(int i=0; i<n; i++){
    	while(!t.empty() && t.top()<=least[i]){
    		u += t.top();
    		t.pop();
    	}
    	t.push(s[i]);
    }
    while(!t.empty()){
    	u += t.top();
    	t.pop();
    }
    
    cout<<u<<endl;

    return 0;    
}