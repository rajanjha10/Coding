//https://www.codechef.com/problems/FGFS

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
		LL k, s, f, p;
		cin>>n>>k;
		map<LL, vector<pair<LL, LL> > > cabin;
		
		while(n--){
			cin>>s>>f>>p;
			cabin[p].push_back({f, s});
		}

		LL ans=0, curr=0;
		for(auto c: cabin){
			sort(c.second.begin(), c.second.end());
			curr = c.second[0].first;
			ans++;
			
			for(int i=1; i<c.second.size(); i++){
				if(c.second[i].second>=curr){
					curr = c.second[i].first;
					ans++;
				}
			}
		}

		cout<<ans<<endl;
	}	

	return 0;
}
