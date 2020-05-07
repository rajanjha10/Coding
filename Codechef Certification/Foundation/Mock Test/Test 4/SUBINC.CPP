// https://www.codechef.com/FLMOCK04/problems/SUBINC

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
		int n;
		cin>>n;
		LL a[n];
		read(a, n);

		int dp[n];
		fill(dp, dp+n, 1);
		for(int i=1; i<n; i++){
			if(a[i]>=a[i-1])
				dp[i] = dp[i-1] + 1;
		}

		long sum = 0;
		for(int i=0; i<n; i++)
			sum += dp[i];
		cout<<sum<<endl;
	}
	
	return 0;
}
