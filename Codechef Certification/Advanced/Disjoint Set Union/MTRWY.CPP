// https://www.codechef.com/problems/MTRWY

#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<"\n"
#define prints(a) for(auto i: a) cout<<i<<" "; cout<<"\n"
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e]

const int maxN = 1e3, maxM = 1e3, maxNM = 1e6;
int id[maxNM], sz[maxNM];
int m1[maxN][maxM], m2[maxN][maxM];
int type[maxNM], X1[maxNM], X2[maxNM], Y1[maxNM], Y2[maxNM];
int mx = 0;

void initialize(int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			m1[i][j] = m2[i][j] = 0;
			id[i*m + j] = i*m + j;
			sz[i*m + j] = 1;
		}
	}

	mx = 1;
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
			sz[x] += sz[y];
			id[y] = x;
			mx = max(mx, sz[x]);
		}
		else{
			sz[y] += sz[x];
			id[x] = y;
			mx = max(mx, sz[y]);
		}
	}
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, m, q;
		cin>>n>>m>>q;

		initialize(n, m);
		for(int i=0; i<q; i++){
			cin>>type[i];

			if(type[i]==1){
				cin>>X1[i]>>Y1[i];
				X1[i]--, Y1[i]--;
				m1[X1[i]][Y1[i]]++;
			}
			else if(type[i]==2){
				cin>>X1[i]>>Y1[i];
				X1[i]--, Y1[i]--;
				m2[X1[i]][Y1[i]]++;
			}
			else if(type[i]==3){
				cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
				X1[i]--, X2[i]--, Y1[i]--, Y2[i]--;
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(j<m-1 && !m1[i][j])
					unionxy(i*m+j, i*m+j+1);
				if(i<n-1 && !m2[i][j])
					unionxy(i*m+j, i*m+j+m);
			}
		}

		LL ans = 0;
		for(int i=q-1; i>=0; i--){
			if(type[i]==1){
				if(--m1[X1[i]][Y1[i]]==0)
					unionxy(X1[i]*m + Y1[i], X1[i]*m + Y1[i] + 1);
			}
			else if(type[i]==2){
				if(--m2[X1[i]][Y1[i]]==0)
					unionxy(X1[i]*m + Y1[i], X1[i]*m + Y1[i] + m);
			}
			else if(type[i]==3){
				if(root(X1[i]*m + Y1[i])==root(X2[i]*m + Y2[i]))
					ans++;
			}
			else
				ans += mx;
		}

		cout<<ans<<"\n";
	}

	return 0;
}
