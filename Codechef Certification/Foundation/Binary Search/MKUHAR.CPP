// https://www.spoj.com/problems/MKUHAR/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const int maxN = 200;
vector<array<int, 6> > a(maxN);

bool eval(int mid, int n, LL m){
	LL need = 0;
	for(int i=0; i<n; i++){
		LL req = a[i][0]*mid - a[i][1];
		if(req<=0)
			continue;
		
		int limit = (req+a[i][2]-1)/a[i][2];
		int sz, rem, cnt_l;
		int mn = INT_MAX;
		
		for(int j=0; j<=limit; j++){
			sz = j*a[i][2];
			rem = req - sz;
			if(rem>0)
				cnt_l = (rem+a[i][4]-1)/a[i][4]; 
			else
				cnt_l = 0;

			mn = min(mn, j*a[i][3]+cnt_l*a[i][5]);
		}

		need += mn;
	}

	return need<=m;
}

int main()
{
	fastio;
	int n;
	LL m;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		read(a[i], 6);

	int low = 0, high = 100000;
	while(low<high){
		int mid = low + (high-low+1)/2;
		if(eval(mid, n, m))
			low = mid;
		else
			high = mid - 1;
	}

	cout<<low<<"\n";

	return 0;
}
