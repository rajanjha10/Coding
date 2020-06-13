// https://www.codechef.com/problems/MAGICSTR

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<"\n"
#define prints(a) for(auto i: a) cout<<i<<" "; cout<<"\n"
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e]

const int maxN = 2e3;
int id[maxN], sz[maxN];
int cntEven[maxN], cntOdd[maxN];

void initialize(int n){
	for(int i=0; i<n; i++){
		id[i] = i;
		sz[i] = i;
	}
}

int root(int x){
	while(x!=id[x]){
		id[x] = id[id[x]];
		x = id[x];
	}

	return x;
}

void unionxy(int u, int v){
	u = root(u);
	v = root(v);

	if(u!=v){
		if(sz[u]>sz[v]){
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
		int n, m;
		cin>>n>>m;

		initialize(n);

		int l, r;
		while(m--){
			cin>>l>>r;
			l--, r--;
			int sz = r-l+1, mid = (l+r)/2;

			if(sz&1)
				cntOdd[mid] = max(cntOdd[mid], sz/2);
			else
				cntEven[mid] = max(cntEven[mid], sz/2);
		}

		for(int i=0; i<n; i++){
			if(cntOdd[i]){
				int sz = cntOdd[i];
				l = i-1, r = i+1;
				while(sz--)
					unionxy(l--, r++);
			}

			if(cntEven[i]){
				int sz = cntEven[i];
				l = i, r = i+1;
				while(sz--)
					unionxy(l--, r++);
			}
		}

		LL ans = 1;
		for(int i=0; i<n; i++){
			if(root(i)==i)
				ans = (ans * 26)%MOD;
		}

		cout<<ans<<"\n";
		memset(cntEven, 0, 4*n);
		memset(cntOdd, 0, 4*n);
	}

	return 0;
}
