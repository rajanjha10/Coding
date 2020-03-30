//https://www.codechef.com/problems/MAXDIFF

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
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		LL w[n];
		read(w, n);

		if(k>n/2)
			sort(w, w+n, greater<LL>());
		else
			sort(w, w+n);

		LL x = 0, y = 0;
		for(int i=0; i<k; i++)
			x += w[i];

		for(int i=k; i<n; i++)
			y += w[i];

		cout<<abs(x-y)<<endl;
	}

	return 0;
}
