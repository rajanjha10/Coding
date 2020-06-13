// https://www.codechef.com/problems/PARITREE

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const int maxN = 100100;
int id[maxN], state[maxN];

void initialize(int n){
	for(int i=0; i<n; i++){
		id[i] = i;
		state[i] = 0;
	}
}

int root(int x){
	if(id[x]==x)
		return x;

	int t = root(id[x]);
	state[x] ^= state[id[x]];
	id[x] = t;

	return id[x];
}

LL mod_pow(LL x, LL y){
	LL res = 1;
	while(y){
		if(y&1)
			res = (res * x)%MOD;

		y >>= 1;
		x = (x*x)%MOD;
	}

	return res;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, q, u, v, x;
		cin>>n>>q;
		initialize(n);
		for(int i=0; i<n-1; i++)
			cin>>u>>v;

		LL ans = -1, diff = n-1;
		while(q--){
			cin>>u>>v>>x;
			if(ans==0)
				continue;

			u -= 1;
			v -= 1;
			int ru = root(u);
			int rv = root(v);

			if(ru==rv){
				if(state[v] != state[u] ^ x)
					ans = 0;
			}
			else{
				diff--;
				state[rv] = state[u] ^ state[v] ^ x;
				id[rv] = ru;
			}
		}

		if(ans==-1)
			ans = mod_pow(2, diff);

		cout<<ans<<"\n";
	}
	
	return 0;
}
