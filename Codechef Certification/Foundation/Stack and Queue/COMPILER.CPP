//https://www.codechef.com/problems/COMPILER

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
        LL i, ans=0, cnt=0;
        string s;
        cin>>s;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='<')
                cnt++;
            else{
                cnt--;
                if(cnt==0)
                    ans = i+1;
                else if(cnt<0)
                    break;
            }
        }

        cout<<ans<<endl;
    }
    return 0;    
}

//Using Stack
int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
    	LL i, ans=0, cntgt=0;
    	string s;
    	stack<char> tags;
    	cin>>s;
    	for(int i=0; i<s.size(); i++){
    		if(s[i]=='>'){
    			if(tags.empty())
    				break;
    			else{
    				cntgt++;
    				if(cntgt==tags.size()){
    					while(!tags.empty()){
    						tags.pop();
    						ans+=2;
    					}
    					cntgt=0;
    				}
    			}
    		}
    		else
    			tags.push(s[i]);
    	}

    	cout<<ans<<endl;
    }
    return 0;    
}
