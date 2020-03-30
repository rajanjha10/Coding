//https://www.codechef.com/problems/CHEFTMA

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
		int n, k, m;
		cin>>n>>k>>m;

		int a[n], b, cd[k+m];
		read(a, n);

		for(int i=0; i<n; i++){
			cin>>b;
			a[i]-=b;
		}

		read(cd, k+m);
		sort(cd, cd+k+m, greater<int>());
		sort(a, a+n, greater<int>());

		LL ans=0;
		int i, j;
		for(i=0, j=0; i<n && j<k+m; j++){
			if(cd[j]>a[i])
				continue;
			else{
				ans += a[i] - cd[j];
				i++;
			}
		}

		while(i<n)
			ans += a[i++];
	
		cout<<ans<<endl;
	}

	return 0;
}
