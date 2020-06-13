// https://www.codechef.com/problems/DISHOWN

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const int maxN = 10e4;
int id[maxN];
LL score[maxN];

void initailize(int n){
	for(int i=0; i<n; i++)
		id[i] = i;
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

	if(x==y)
		cout<<"Invalid query!"<<"\n";
	else{
		if(score[x]>score[y])
			id[y] = x;
		else if(score[y]>score[x])
			id[x] = y;
	}
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n;
		initailize(n);
		read(score, n);

		cin>>q;
		while(q--){
			int op, x, y;
			cin>>op;
			if(op==0){
				cin>>x>>y;
				unionxy(x-1, y-1);
			}
			else{
				cin>>x;
				cout<<root(x-1)+1<<"\n";
			}
		}
	}

	return 0;
}
