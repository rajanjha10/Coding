//http://codeforces.com/contest/5/problem/C

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
    stack<int> st;
    int m=0, cnt=1, n=s.size(); 
    int d[n], c[n];
    memset(c, -1, sizeof(c));
    for(int i=0; i<s.size(); i++){
    	if(s[i]=='(')
    		st.push(i);
    	else{
    		if(st.empty())
    			d[i]=-1;
    		else{
    			d[i]=st.top();
    			st.pop();
    			c[i] = d[i];
    			if(d[i]!=0 && s[d[i]-1]==')' && c[d[i]-1]!=-1)
    				c[i] = c[d[i]-1];
    		}
    	}
    }
    for(int i=0; i<s.size(); i++){
    	if(c[i]==-1)
    		continue;
    	if(i-c[i]+1>m){
    		m = i-c[i]+1;
    		cnt=1;
    	}
    	else if(i-c[i]+1==m)
    		cnt++;
    }

    cout<<m<<" "<<cnt<<endl;
    return 0;    
}