//https://www.spoj.com/problems/MDOLLS/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool cmp(pair<int, int>& m1, pair<int, int>& m2){
	if(m1.first==m2.first)
		return m1.second<m2.second;

	return m1.first>m2.first;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, w, h;
		cin>>n;
		vector<pair<int, int> > m(n);
		for(int i=0; i<n; i++){
			cin>>w>>h;
			m[i] = {w, h};
		}
		sort(m.begin(), m.end(), cmp);
		
		int dp[n];
		dp[0] = 1;
		for(int i=1; i<n; i++){
			dp[i] = 1;
			w = m[i].first;
			h = m[i].second;
			for(int j=0; j<i; j++){
				if(m[j].first>w && m[j].second<h)
					dp[i] = max(dp[j]+1, dp[i]);
			}
		}
		
		cout<<*max_element(dp, dp+n)<<endl;
	}
	return 0;
}
