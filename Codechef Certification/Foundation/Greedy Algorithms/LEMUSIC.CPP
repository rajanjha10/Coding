//https://www.codechef.com/problems/LEMUSIC

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
		LL b, l;
		vector<pair<LL, LL> > band(n);

		for(int i=0; i<n; i++){
			cin>>b>>l;
			band[i] = {b, l};
		}

		sort(band.begin(), band.end());

		LL ans=0;
		vector<LL> shortSongs;

		for(int i=0; i<band.size(); i++){
			if(i==0 || band[i-1].first!=band[i].first)
				shortSongs.push_back(band[i].second);
			else
				ans += band[i].second;
		}
		
		sort(shortSongs.begin(), shortSongs.end());
		ans = ans * shortSongs.size();

		for(int i=0; i<shortSongs.size(); i++)
			ans += shortSongs[i]*(i+1);

		cout<<ans<<endl;
	}

	return 0;
}
