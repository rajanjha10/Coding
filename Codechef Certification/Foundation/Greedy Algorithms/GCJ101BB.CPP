//https://www.spoj.com/problems/GCJ101BB/

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
	int C;
	cin>>C;
	for(int c=1; c<=C; c++){
		int n, k, t;
		LL b;
		cin>>n>>k>>b>>t;
		LL x[n];
		int v[n];

		read(x, n);
		read(v, n);

		int cnt=0;
		for(int i=0; i<n; i++){
			x[i] = b - x[i];
			x[i] = x[i]/v[i] + ((x[i]%v[i]==0)?0:1);
			if(x[i]<=t)
				cnt++;
		}

		cout<<"Case #"<<c<<": ";
		if(cnt<k){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}

		LL ans=0;
		cnt=0;
		for(int i=n-1; ~i && k>0; i--){
			if(x[i]>t)
				cnt++;
			else{
				ans += cnt;
				k--;
			}
		}
		
		cout<<ans<<endl;
	}

	return 0;
}
