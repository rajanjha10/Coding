//https://www.codechef.com/problems/MATRIX2

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
	int n, m;
	cin>>n>>m;
	char c;
	LL dp[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>c;
			dp[i][j] = c-'0';
		}
	}

	for(int i=n-2; i>=0; i--){
		for(int j=m-2; j>=0; j--){
			if(dp[i][j])
				dp[i][j] = min(dp[i][j+1], dp[i+1][j+1]) + 1;
		}
	}

	LL ans=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			ans += dp[i][j];
	}

	cout<<ans<<endl;
	return 0;
}
