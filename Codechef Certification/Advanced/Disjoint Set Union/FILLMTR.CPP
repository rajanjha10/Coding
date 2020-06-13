// https://www.codechef.com/problems/FILLMTR

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const int maxN = 1e5;
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

	int p = root(id[x]);
	state[x] ^= state[id[x]];
	id[x] = p;

	return id[x];
}

int main()
{
	fastio;
	LL t;
	cin>>t;
	while(t--){
		LL n, q, i, j, v;
		string ans = "yes";
		cin>>n>>q;
		initialize(n);

		while(q--){
			cin>>i>>j>>v;
			if(ans=="no")
				continue;

			i -= 1;
			j -= 1;
			int ri = root(i);
			int rj = root(j);

			if(ri==rj){
				if(state[j] != state[i] ^ v)
					ans = "no";
			}
			else{
				id[rj] = ri;
				state[rj] = state[i] ^ state[j] ^ v;
			}
		}

		cout<<ans<<"\n";

	}
	
	return 0;
}
