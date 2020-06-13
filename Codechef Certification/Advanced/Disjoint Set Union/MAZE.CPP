// https://www.codechef.com/problems/MAZE

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<"\n"
#define prints(a) for(auto i: a) cout<<i<<" "; cout<<"\n"
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e]

vector<int> id, sz;
map<LL, int> points;
set<pair<LL, LL> > edges;

LL r, c, p1, p2, m, n, ind;

void convert(LL x1, LL y1, LL x2, LL y2){
	if(x1==x2){
		LL off = (x1-1)*m;
		p1 = off + min(y1, y2);
		p2 = p1-m;

		if(x1==1)
			p2 = 0;
		else if(x1==r)
			p1 = 0;
	}
	else{
		LL off = (min(x1, x2) - 1)*m;
		p1 = off + y1;
		p2 = p1-1;

		if(y1==1)
			p2 = 0;
		else if(y1==c)
			p1 = 0;
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

void make(LL p){
	if(p==0)
		return;

	if(points[p]==0){
		points[p] = ind;
		id.push_back(ind++);
		sz.push_back(1);
	}
}

void solve(){
	LL w;
	LL x1, y1, x2, y2;
	cin>>r>>c>>w;

	if(r==1 || c==1){
		if(r==1 && c==1)
			cout<<"Chefland is doomed"<<"\n";
		else
			cout<<!w<<"\n";

		while(w--)
			cin>>x1>>y1>>x2>>y2;

		return;
	}

	id.clear();
	sz.clear();
	points.clear();
	edges.clear();	

	n = r-1, m = c-1, ind = 1;
	points[0] = 0;
	id.push_back(0);
	sz.push_back(1);
	int res = 2;
	
	while(w--){
		cin>>x1>>y1>>x2>>y2;
		convert(x1, y1, x2, y2);

		edges.insert({p1, p2});
		edges.insert({p2, p1});

		make(p1);
		make(p2);

		p1 = points[p1];
		p2 = points[p2];

		p1 = root(p1);
		p2 = root(p2);

		if(p1==p2)
			res = 0;

		unionuv(p1, p2);
	}

	LL d[] = {-m, 1, m, -1};

	if(res){
		for_each(points.begin(), points.end(), [&res, &d](const pair<LL, LL>& pt){
			LL p = pt.first;
			if(p!=0){
				int cnt = 0;
				for(int i=0; i<4 && res!=1; i++){
					LL np = max(0LL, p+d[i]);
					if(np>m*n || (p%m==0 && i==1) || (np%m==0 && i==3))
						np = 0;

					if(np==0)
						cnt++;

					if(edges.find({p, np})==edges.end() && points.find(np)!=points.end()){
						if(root(points[np])==root(pt.second))
							res = 1;
					}
				}

				if(edges.find({p, 0})!=edges.end() && cnt>1)
					res = 1;

				if(res==1)
					return;
			}
		});			
	}

	cout<<res<<"\n";
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--)
		solve();

	return 0;
}
