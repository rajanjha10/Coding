// http://codeforces.com/contest/151/problem/D

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<"\n"
#define prints(a) for(auto i: a) cout<<i<<" "; cout<<"\n"
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e]

const int maxN = 2000;
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
	int n, m, k;
	cin>>n>>m>>k;
	initialize(n);

	LL ans = 1;
	for(int i=0; i+k-1<n; i++){
		int left = i, right = i+k-1;
		while(left<right){
			unionxy(left, right);
			left++;
			right--;
		}
	}

	for(int i=0; i<n; i++){
		if(root(i)==i)
			ans = (ans * m)%MOD;
	}

	cout<<ans<<"\n";

	return 0;
}
