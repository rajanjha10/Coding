//https://www.codechef.com/problems/AMSGAME2

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

LL dp[61][10010];
int a[61];

LL eval(int i, int n, int currGcd){
	if(i==n){
		if(currGcd==1)
			return 1;
		else
			return 0;
	}

	if(dp[i][currGcd]!=-1)
		return dp[i][currGcd];

	LL include = eval(i+1, n, __gcd(currGcd,a[i]));
	LL exclude = eval(i+1, n, currGcd);

	return dp[i][currGcd] = include + exclude;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		read(a, n);

		memset(dp, -1, sizeof(dp));
		LL ans=0;
		for(int i=0; i<n; i++)
			ans += eval(i+1, n, a[i]);
			
		cout<<ans<<endl;

	}
	return 0;
}
