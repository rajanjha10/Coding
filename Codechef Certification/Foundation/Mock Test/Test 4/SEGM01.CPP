// https://www.codechef.com/FLMOCK04/problems/SEGM01

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int seen = 0;
		int n = s.size();
		for(int i=0; i<n; i++){
			if(s[i]=='1' && !seen){
				while(i<n && s[i]=='1')
					i++;
				seen = 1;
			}
			else if(s[i]=='1' && seen){
				seen = 2;
				break;
			}
		}

		if(seen==0 || seen==2)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}
	
	return 0;
}
