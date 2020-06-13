// http://codeforces.com/problemset/problem/547/B

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<"\n"
#define prints(a) for(auto i: a) cout<<i<<" "; cout<<"\n"
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e]

const int maxN = 2e5;
int sz[maxN], id[maxN], visited[maxN];

void initialize(int n){
	for(int i=0; i<n; i++){
		id[i] = i;
		sz[i] = 1;
		visited[i] = 0;
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
	cin>>n;
	LL h;
	vector<pair<LL, int> > a(n);
	initialize(n);

	for(int i=0; i<n; i++){
		cin>>h;
		a[i] = {h, i};
	}

	LL ans[n];
	sort(a.begin(), a.end(), greater<pair<LL, int> >());

	int cnt = 1;
	for(int i=0; i<n; i++){
		int index = a[i].second;
		visited[index] = 1;

		if(index && visited[index-1])
			unionxy(index, index-1);
		if(index!=n-1 && visited[index+1])
			unionxy(index, index+1);

		int size = sz[root(index)];
		while(cnt<=size)
			ans[cnt++] = a[i].first;
	}

	for(int i=1; i<=n; i++)
		cout<<ans[i]<<" ";

	return 0;
}
