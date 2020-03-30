//https://www.codechef.com/problems/TADELIVE

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
	int n, x, y;
	cin>>n>>x>>y;
	
	int a[n], b[n], d[n];
	read(a, n);
	read(b, n);

	LL sum=0;
	for(int i=0; i<n; i++){
		sum += a[i];
		d[i] = b[i] - a[i];
	}

	sort(d, d+n, greater<int>());
	
	LL ans = -1;
	for(int i=0; i<y; i++){
		sum += d[i];
		if(i>=n-x-1)
			ans = max(ans, sum);
	}

	cout<<ans<<endl;
	return 0;
}
