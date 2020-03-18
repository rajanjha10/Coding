//https://www.spoj.com/problems/MCARDS/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int find_LIS(vector<int> a){
	int dp[a.size()];
	for(int i=0; i<a.size(); i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(a[i] > a[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}
	
	return *max_element(dp, dp+a.size());
}

int main()
{
	fastio;
	int c, n, tot, x, y, ans=INT_MAX;
	cin>>c>>n;
	tot = c*n;
	
	int a[c+1][n+1];
	for(int i=1; i<=tot; i++){
		cin>>x>>y;
		a[x][y] = i;
	}

	vector<int> per(c);
	for(int i=1; i<=c; i++)
		per[i-1] = i;

	do{
		vector<int> order;
		for(int i=0; i<c; i++){
			for(int j=1; j<=n; j++)
				order.push_back(a[per[i]][j]);
		}

		ans = min(ans, tot - find_LIS(order));
	
	}while(next_permutation(per.begin(), per.end()));

	cout<<ans<<endl;

	return 0;
}
