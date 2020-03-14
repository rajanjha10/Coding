//https://www.codechef.com/problems/GALACTIK

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

vector<LL> id, sz, cost;

void initialize(LL n){
	for(LL i=0; i<n; i++){
		id.push_back(i);
		sz.push_back(1);
	}
}

LL root(LL i){
	while(id[i]!=i){
		id[i] = id[id[i]];
		i = id[i];
	}

	return i;
}

void unionAB(LL a, LL b){
	LL ra = root(a);
	LL rb = root(b);
	if(ra!=rb){
		if(sz[ra]>sz[rb]){
			id[rb] = ra;
			sz[ra] += rb;
			cost[ra] = min(cost[ra], cost[rb]);
		}
		else{
			id[ra] = rb;
			sz[rb] += ra;
			cost[rb] = min(cost[ra], cost[rb]);
		}
	}
}

int main()
{
	fastio;
	LL n, m, c;
	cin>>n>>m;
	initialize(n);
	LL a[m], b[m];
	for(LL i=0; i<m; i++)
		cin>>a[i]>>b[i];
	
	for(LL i=0; i<n; i++){
		cin>>c;
		if(c>=0)
			cost.push_back(c);
		else
			cost.push_back(INT_MAX);
	}
	
	for(LL i=0; i<m; i++)
		unionAB(a[i]-1, b[i]-1);
	
	map<LL, LL> minCost;
	bool flag=0;
	for(LL i=0; i<n; i++){
		LL r = root(i);
		if(cost[r]==INT_MAX)
			flag=1;
		minCost[r] = cost[r];	
	}

	if(flag){
		if(minCost.size()==1)
			cout<<0<<endl;
		else
			cout<<-1<<endl;

		return 0;
	}

	LL ans = 0, mn=INT_MAX;
	for(auto it=minCost.begin(); it!=minCost.end(); it++){
		mn = min(mn, it->second);
		ans += it->second;
	}
	ans = mn*(minCost.size()-1) + ans - mn;
	
	cout<<ans<<endl;
	return 0;
}
