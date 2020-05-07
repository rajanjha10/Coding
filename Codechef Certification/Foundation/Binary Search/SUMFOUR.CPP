// https://www.spoj.com/problems/SUMFOUR/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
	fastio;
	int n;
	cin>>n;

	LL a[n], b[n], c[n], d[n];
	for(int i=0; i<n; i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	
	vector<LL> sumsab, sumscd;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			sumsab.push_back(a[i]+b[j]);
			sumscd.push_back(c[i]+d[j]);
		}
	}

	sort(sumscd.begin(), sumscd.end());

	LL cnt = 0;
	for(int i=0; i<sumsab.size(); i++){
		cnt += upper_bound(sumscd.begin(), sumscd.end(), -(sumsab[i])) - sumscd.begin();
		cnt -= lower_bound(sumscd.begin(), sumscd.end(), -(sumsab[i])) - sumscd.begin();
	}

	cout<<cnt<<endl;

	return 0;
}
