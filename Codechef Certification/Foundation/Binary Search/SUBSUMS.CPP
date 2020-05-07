// https://www.spoj.com/problems/SUBSUMS/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

void cal_subsets(vector<LL> v, vector<LL>& s){
	for(LL i=0; i<(1<<v.size()); i++){
		LL sum = 0;
		for(LL j=0; j<v.size(); j++){
			if(1<<j & i)
				sum += v[j];
		}

		s.push_back(sum);
	}
}

int main()
{
	fastio;
	int n;
	LL a, b;
	cin>>n>>a>>b;

	vector<LL> h1(n/2), h2(n-n/2);
	read(h1, h1.size());
	read(h2, h2.size());

	vector<LL> x, y;
	cal_subsets(h1, x);
	cal_subsets(h2, y);

	sort(y.begin(), y.end());
	
	LL cnt = 0;
	for(LL i=0; i<x.size(); i++){
		cnt += upper_bound(y.begin(), y.end(), b-x[i]) - y.begin();
		cnt -= lower_bound(y.begin(), y.end(), a-x[i]) - y.begin();
	}
	
	cout<<cnt<<endl;

	return 0;
}
