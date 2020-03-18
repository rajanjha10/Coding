//https://www.spoj.com/problems/MIXTURES/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

//Top Down Dp
int dp[101][101];
int a[101];

int sum(int i, int j){
	int s = 0;
	for(int k=i; k<=j; k++)
		s = (s+a[k])%100;
	
	return s;
}

int eval(int i, int j){
	if(dp[i][j]!=-1)
		return dp[i][j];

	if(i==j)
		return 0;

	for(int k=i; k<j; k++){
		int v = eval(i, k) + eval(k+1, j) + sum(i, k)*sum(k+1, j);
		dp[i][j] = (dp[i][j]==-1) ? v : dp[i][j];
		dp[i][j] = min(dp[i][j], v);
	}

	return dp[i][j];
}

int main()
{
	fastio;
	int n;
	while(cin>>n){
		read(a, n);
		memset(dp, -1, sizeof(dp));
		cout<<eval(0, n)<<endl;
	}

	return 0;
}

//Bottom Up DP
int main()
{
	fastio;
	int n;
	while(cin>>n){
		int color[n];
		read(color, n);
		LL dp[n][n], sum[n][n] = {0};
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
				dp[i][j] = INT_MAX;

			dp[i][i] = 0;
			sum[i][i] = color[i];
		}

		for(int l=1; l<n; l++){
			for(int i=0; i<n-l; i++){
				int j = i+l;
				for(int k=i; k<j; k++){
					LL v = dp[i][k] + dp[k+1][j] + sum[i][k]*sum[k+1][j];
					if(v<dp[i][j]){
						dp[i][j] = v;
						sum[i][j] = (sum[i][k] + sum[k+1][j])%100;
					}
				}
			}
		}

		cout<<dp[0][n-1]<<endl;
	}
	
	return 0;
}
