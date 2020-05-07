// https://www.codechef.com/FLPAST01/problems/POLMUL

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
		int n, m;
		cin>>n>>m;

		int pn[n], pm[m];
		read(pn, n);
		read(pm, m);

		LL ans[n+m-1]={0};
		for(int i=0; i<m; i++){
			for(int j=0, k=i; j<n; j++)
				ans[k++] += pm[i]*pn[j];
		}

		print(ans, n+m-1);
	}

	return 0;
}
