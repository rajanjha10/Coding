//https://www.codechef.com/problems/FROGV

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
	int n, p;
	LL k, v;
	cin>>n>>k>>p;
	vector<pair<LL, int> > a(n);
	for(int i=0; i<n; i++){
		cin>>v;
		a[i] = {v, i};
	}

	sort(a.begin(), a.end(), greater<pair<LL, int> >());
	int dp[n];
	dp[a[0].second]=0;

	for(int i=1; i<n; i++){
		if((a[i-1].first - a[i].first)<=k)
			dp[a[i].second] = dp[a[i-1].second];
		else
			dp[a[i].second] = dp[a[i-1].second]+1;
	}

	while(p--){
		int x, y;
		cin>>x>>y;
		if(dp[x-1]==dp[y-1])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}
