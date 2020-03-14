//https://www.codechef.com/problems/TADELIVE

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

//Top Down DP
int a[100010], b[100010];
int n, x, y;
LL dp[5010][5010];

LL eval(int i, int j){
	if(i==n)
		return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	LL include = 0, exclude = 0;
	if(j<x)
		include = a[i] + eval(i+1, j+1);
	if((i-j)<y)
		exclude = b[i] + eval(i+1, j);

	return dp[i][j] = max(include, exclude);
}	

int main()
{
	fastio;
	cin>>n>>x>>y;
	read(a, n);
	read(b, n);
	memset(dp, -1, sizeof(dp));

	cout<<eval(0, 0)<<endl;
	return 0;
}

//Bottom Up DP
int main()
{
	fastio;
	int n, x, y;
	cin>>n>>x>>y;
	int a[n+1], b[n+1];
	for(int i=1; i<=n; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
		cin>>b[i];
	
	LL dp[n+1][x+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=x && j<=i; j++){
			if(j<=x)
				dp[i][j] = dp[i-1][j-1] + a[i];
			if((i-j)<=y)
				dp[i][j] = max(dp[i][j], dp[i-1][j]+b[i]);
		}
	}
	
	LL ans=0;
	for(int i=1; i<=x; i++)
		ans = max(ans, dp[n][i]);

	cout<<ans<<endl;
	return 0;
}

