//https://www.codechef.com/problems/LAPIN

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
    string s;
    int cnt[27] = {0};
    cin>>t;
    while(t--){
    	cin>>s;
    	int n = s.length(), flag=0;
    	for(int i=0, j=n-1; i<n/2; i++, j--){
    		cnt[s[i]-'a']++;
    		cnt[s[j]-'a']--;
    	}

    	for(int i=0; i<27; i++){
    		if(cnt[i]!=0){
    			flag=1;
    			break;
    		}
    	}

    	if(flag)
    		cout<<"NO"<<endl;
    	else
    		cout<<"YES"<<endl;
    	memset(cnt, 0, sizeof(cnt));
    }
    return 0;    
}
