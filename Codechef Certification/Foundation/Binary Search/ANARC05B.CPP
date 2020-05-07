// https://www.spoj.com/problems/ANARC05B/

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
	while(1){
		int n, m;
		cin>>n;
		if(n==0)
			break;

		vector<int> a(n);
		read(a, n);
		cin>>m;
		vector<int> b(m);
		read(b, m);

		vector<pair<int, int> > index;
		for(int i=0; i<n; i++){
			int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			if(j<m && b[j]==a[i])
				index.push_back({i, j});
		}

		index.push_back({n-1, m-1});

		for(int i=1; i<n; i++)
			a[i] += a[i-1];
		for(int i=1; i<m; i++)
			b[i] += b[i-1];

		int x = index[0].first, y = index[0].second;
		int ans = max(a[x], b[y]);
		
		for(int i=1; i<index.size(); i++){
			ans += max(a[index[i].first] - a[x], b[index[i].second] - b[y]);
			x = index[i].first, y = index[i].second;
		}

		cout<<ans<<endl;
	}

	return 0;
}
