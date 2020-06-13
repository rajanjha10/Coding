// https://www.codechef.com/problems/SETELE

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<"\n"
#define prints(a) for(auto i: a) cout<<i<<" "; cout<<"\n"
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e]

const int maxN = 1e5;
int id[maxN], sz[maxN];

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

void unionuv(int u, int v){
	if(u!=v){
		if(sz[u] > sz[v]){
			sz[u] += sz[v];
			id[v] = u;
		}
		else{
			sz[v] += sz[u];
			id[u] = v;
		}
	}
}

int main()
{
	fastio;
	int n;
	cin>>n;

	initialize(n);
	vector<array<LL, 3> > edg(n-1);

	int u, v;
	LL c;
	for(int i=0; i<n-1; i++){
		cin>>u>>v>>c;
		edg[i] = {u-1, v-1, c};
	}

	sort(edg.begin(), edg.end(), [&](const array<LL, 3>& x, const array<LL, 3>& y){
		return x[2]<y[2];
	});

	long double ans = 0, sum = 0;
	for(int i=0; i<n-1; i++){
		u = edg[i][0], v = edg[i][1], c = edg[i][2];

		u = root(u);
		v = root(v);

		sum += (long double) sz[u] * sz[v] * c;
		ans += (long double) c;

		unionuv(u, v);
	}

	sum *= 2.0;
	sum /= (long double)n;
	sum /= (long double)(n-1);

	ans -= sum;

	cout<<fixed<<setprecision(3)<<ans<<"\n";

	return 0;
}
