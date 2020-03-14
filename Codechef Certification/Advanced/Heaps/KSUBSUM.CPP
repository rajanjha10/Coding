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
		multiset<LL> mh;
		LL a[n+1];
		
		a[0] = 0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
			a[i] += a[i-1];
		}

		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				LL x = a[j] - a[i-1];
				if(mh.size()<k3)
					mh.insert(x);
				else if(x>*mh.begin()){
					mh.erase(mh.begin());
					mh.insert(x);
				}
			}
		}

		vector<LL> ans(mh.rbegin(), mh.rend());
		cout<<ans[k1-1]<<" "<<ans[k2-1]<<" "<<ans[k3-1]<<endl;
	}
	return 0;
}
