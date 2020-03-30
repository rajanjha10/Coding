//https://www.spoj.com/problems/FASHION/

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
		int n;
		cin>>n;
		int m[n], w[n];
		read(m, n);
		read(w, n);

		sort(m, m+n);
		sort(w, w+n);

		LL ans=0;
		for(int i=0; i<n; i++)
			ans += m[i]*w[i];
		
		cout<<ans<<endl;

	}

	return 0;
}
