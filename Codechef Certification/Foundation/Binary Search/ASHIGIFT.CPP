// https://www.codechef.com/problems/ASHIGIFT

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool eval(vector<pair<LL, pair<LL, LL> > > points, LL men){
	for(LL i=0; i<points.size(); i++){
		if(points[i].second.first<=men)
			men += points[i].second.second;

		if(men<=0)
			return false;
	}

	return true;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		LL x, b, xi, yi, c, p, q, r, maxMen=0;
		cin>>x>>b;
		vector<pair<LL, pair<LL, LL> > > points;

		for(LL i=0; i<b; i++){
			cin>>xi>>yi;
			points.push_back({xi, {0, -yi}});
			maxMen += yi;
		}

		cin>>c;
		for(LL i=0; i<c; i++){
			cin>>p>>q>>r;
			points.push_back({p, {q, r}});
		}

		sort(points.begin(), points.end());

		LL start = 1, end = maxMen+1;
		while(start<end){
			LL mid = start + (end - start)/2;
			if(eval(points, mid))
				end = mid;
			else
				start = mid+1;
		}

		cout<<start<<endl;

	}

	return 0;
}
