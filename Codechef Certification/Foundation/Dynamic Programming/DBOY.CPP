//https://www.codechef.com/problems/DBOY

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
		int n, m=0;
		cin>>n;
		int h[n], k[n];
		
		read(h, n);
		read(k, n);

		for(int i=0; i<n; i++){
			h[i] *= 2;
			m = max(h[i], m);
		}

		LL dp[m+1];
		for(int i=0; i<=m; i++)
			dp[i] = INT_MAX;

		dp[0] = 0;
		for(int i=0; i<=m; i++){
			for(int j=0; j<n; j++){
				if(i+k[j]<=m)
					dp[i+k[j]] = min(dp[i+k[j]], dp[i]+1);
			}
		}

		LL ans=0;
		for(int i=0; i<n; i++)
			ans += dp[h[i]];
		
		cout<<ans<<endl;
	}

	return 0;
}
