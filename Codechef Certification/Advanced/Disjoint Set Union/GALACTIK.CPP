//https://www.codechef.com/problems/GALACTIK

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const int maxN = 10e5; 
int id[maxN], sz[maxN], cost[maxN];

void initialize(int n){
	for(int i=0; i<n; i++){
		id[i] = i;
		sz[i] = 1;
	}
}

int root(int x){
	while(x!=id[x]){
		id[x] = id[id[x]];
		x = id[x];
	}

	return x;
}

void unionxy(int x, int y){
	x = root(x);
	y = root(y);

	if(x!=y){
		if(sz[x]>sz[y]){
			id[y] = x;
			sz[x] += sz[y];
		}
		else{
			id[x] = y;
			sz[y] += sz[x];
		}
	}
}

int main()
{
	fastio;
	int n;
	LL m;
	cin>>n>>m;
	initialize(n);

	for(LL i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		unionxy(u-1, v-1);
	}

	read(cost, n);
	for(int i=0; i<n; i++){
		if(cost[i]<0)
			cost[i] = INT_MAX;
	}

	set<int> s;

	for(int i=0; i<n; i++){
		int r = root(i);
		cost[r] = min(cost[r], cost[i]);
		s.insert(r);
	}

	LL ans = 0;
	int minCost = INT_MAX;
	for(auto i: s){
		if(cost[i]==INT_MAX){
			ans = -1;
			break;
		}

		minCost = min(minCost, cost[i]);
		ans += cost[i];
	}

	if(~ans){
		ans -= minCost;
		ans += (s.size()-1)*(LL)minCost;
	}
	else if(s.size()==1)
		ans = 0;

	cout<<ans<<"\n";

	return 0;
}
