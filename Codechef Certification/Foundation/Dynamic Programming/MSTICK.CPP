//https://www.spoj.com/problems/MSTICK/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2){
	if(p1.first==p2.first)
		return p1.second > p2.second;

	return p1.first > p2.first;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, l, w;
		cin>>n;
		vector<pair<int, int> > a(n);
		for(int i=0; i<n; i++){
			cin>>l>>w;
			a[i] = {l, w};
		}

		sort(a.begin(), a.end(), cmp);

		int dp[n];
		for(int i=0; i<n; i++){
			dp[i] = 1;
			for(int j=0; j<i; j++){
				if(a[j].second < a[i].second)
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		cout<<*max_element(dp, dp+n)<<endl;
	}
	return 0;
}
