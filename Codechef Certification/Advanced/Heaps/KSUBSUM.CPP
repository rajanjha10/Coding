//https://www.codechef.com/problems/KSUBSUM

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
		int n, k1, k2, k3;
		cin>>n>>k1>>k2>>k3;

		int a[n];
		read(a, n);

		multiset<LL> m;
		for(int i=0; i<n; i++){
			LL s = 0;
			for(int j=i; j<n; j++){
				s += a[j];
				if(m.size()<k3)
					m.insert(s);
				else if(s > *m.begin()){
					m.erase(m.begin());
					m.insert(s);
				}
			}
		}

		vector<LL> ans(m.rbegin(), m.rend());
		cout<<ans[k1-1]<<" "<<ans[k2-1]<<" "<<ans[k3-1]<<"\n";

	}

	return 0;
}
