// https://www.codechef.com/problems/CAPIMOVE

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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		LL p[n+1];
		multiset<pair<LL, LL> > pq;
		for(int i=1; i<=n; i++){
			cin>>p[i];
			pq.insert({p[i], i});
		}

		vector<vector<int> > adj(n+1);
		for(int i=0; i<n-1; i++){
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for(int i=1; i<=n; i++){
			for(auto v: adj[i])
				pq.erase(pq.find({p[v], v}));
			
			pq.erase(pq.find({p[i], i}));
			cout<<(*pq.rbegin()).second<<" ";

			for(auto v: adj[i])
				pq.insert({p[v], v});

			pq.insert({p[i], i});
		}

		cout<<"\n";
	}	

	return 0;
}
