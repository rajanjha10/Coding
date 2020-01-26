//https://www.spoj.com/problems/ONP/

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl;
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
    	string s, ans="";
    	cin>>s;
    	stack<char> operators;
    	for(int i=0; i<s.size(); i++){
    		if(s[i]=='(')
    			operators.push(s[i]);
    		else if(s[i]==')'){
    			while(operators.top()!='('){
    				ans+=operators.top();
    				operators.pop();
    			}
    			operators.pop();
    		}
    		else if(s[i]>='a' && s[i]<='z')
    			ans+=s[i];
    		else
    			operators.push(s[i]);
    	}

    	cout<<ans<<endl;
    }
    return 0;    
}
