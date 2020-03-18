//https://www.spoj.com/problems/AIBOHP/

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
		string sr = s;
		reverse(sr.begin(), sr.end());

		int n = s.size(); 
		int dp[n+1][n+1];

		for(int i=0; i<=n; i++)
			dp[0][i] = dp[i][0] = 0;
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(s[i-1]==sr[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}

		cout<<n-dp[n][n]<<endl;
	}
	
	return 0;
}
