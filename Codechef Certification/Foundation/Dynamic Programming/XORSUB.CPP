//https://www.codechef.com/problems/XORSUB

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

//Top Down DP
bool dp[1001][1024] = {0};

void eval(int a[], int i, int n, int currXor){
	if(i==n)
		return; 

	if(dp[i][currXor])
		return;

	dp[i][currXor] = 1;
	eval(a, i+1, n, currXor);
	dp[i][currXor^a[i]] = 1;
	eval(a, i+1, n, currXor^a[i]);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		read(a, n);

		memset(dp, 0, sizeof(dp));
		eval(a, 0, n, 0);

		int ans=k;
		for(int i=0; i<1024; i++){
			if(dp[n-1][i])
				ans = max(ans, i^k);
		}

		cout<<ans<<endl;
	}

	return 0;
}

//State Space Reduction
//Bottom Up DP 
int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		read(a, n);
		
		bool dp[1024] = {0};
		dp[0] = 1;
		for(int i=0; i<n; i++){
			for(int j=0; j<1024; j++)
				dp[j^a[i]] |= dp[j];
		}
		
		int ans=k;
		for(int i=0; i<1024; i++)
			if(dp[i])
				ans = max(ans, i^k);
		
		cout<<ans<<endl;
	}

	return 0;
}
