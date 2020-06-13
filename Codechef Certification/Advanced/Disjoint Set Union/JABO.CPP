// https://www.codechef.com/problems/JABO

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const LL maxN = 500LL * 2500;
LL v[maxN];
LL sz[maxN], id[maxN];

void initialize(LL n){
	for(LL i=0; i<n; i++){
		id[i] = i;
		sz[i] = 1;
		v[i] = 0;
	}
}

int eval(char c){
	if(c<='Z')
		return c - 'A';
	else
		return c - 'a' + 26;
}

LL convert(char c1, char c2){
	LL u, v;
	u = eval(c1), v = eval(c2);

	return (u*52 + v)-1;
}

LL root(LL x){
	while(id[x]!=x){
		id[x] = id[id[x]];
		x = id[x];
	}

	return x;
}

void unionxy(LL x, LL y){
	x = root(x);
	y = root(y);

	if(x!=y){
		if(sz[x]>sz[y]){
			id[y] = x;
			sz[x] += sz[y];
			v[x] += v[y];
		}
		else{
			id[x] = y;
			sz[y] += sz[x];
			v[y] += v[x];
		}
	}
}

int main()
{
	fastio;
	LL q, c[4];
	LL n, m, x, y;
	string s;
	cin>>q>>n>>m;

	initialize(n*m);

	while(q--){
		cin>>s;
		switch(s[0]){
			case 'W':
					for(int i=1, j=0; i<s.size(); i+=2)
						c[j++] = convert(s[i], s[i+1]);
					unionxy((c[1]/5)*m + c[0], (c[3]/5)*m + c[2]);

					break;

			case 'V':
					y = convert(s[1], s[2]);
					x = convert(s[3], s[4]);
					v[root((x/5)*m + y)]++;

					break;
			
			case 'R':
					y = convert(s[1], s[2]);
					x = convert(s[3], s[4]);
					v[root((x/5)*m + y)]--;

					break;
			
			case 'L':
					for(int i=1, j=0; i<s.size(); i+=2)
						c[j++] = convert(s[i], s[i+1]);
					
					LL r1 = root((c[1]/5)*m + c[0]);
					LL r2 = root((c[3]/5)*m + c[2]);

					if((v[r1]>0 && v[r2]==0) || (v[r2]>0 && v[r1]==0))
						cout<<"ON"<<"\n";
					else
						cout<<"OFF"<<"\n";

					break;
		}

	}

	return 0;
}
