// https://www.codechef.com/problems/BIGOF01

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<"\n"
#define prints(a) for(auto i: a) cout<<i<<" "; cout<<"\n"
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e]

const int maxN = 1e6;
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
	u = root(u);
	v = root(v);

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
	int t;
	cin>>t;
	while(t--){
		int n, q, c;
		cin>>n>>c;

		initialize(n);

		int u, v;
		while(c--){
			cin>>u>>v;
			unionuv(u-1, v-1);
		}

		cin>>q;
		while(q--){
			cin>>u>>v;
			if(root(u-1)==root(v-1))
				cout<<"Yes"<<"\n";
			else
				cout<<"No"<<"\n";
		}

	}

	return 0;
}
