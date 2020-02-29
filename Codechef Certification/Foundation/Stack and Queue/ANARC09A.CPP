//https://www.spoj.com/problems/ANARC09A/

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
    int n=1;
    string s;
    while(1){
    	cin>>s;
    	int cnt=0;
    	if(s[0]=='-')
    		break;
    	stack<char> st;
    	for(int i=0; i<s.size(); i++){
    		if(!st.empty() && st.top()=='{' && s[i]=='}')
   				st.pop();
    		else 
    			st.push(s[i]);		
    	}
    	while(!st.empty()){
    		char top = st.top();
    		st.pop();
    		if(st.top()=='}' && top=='{')
    			cnt+=2;
    		else
    			cnt++;
    		st.pop();		
    	}
    	
    	cout<<(n++)<<". "<<cnt<<endl;
    }
    
    return 0;    
}