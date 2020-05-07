// https://www.codechef.com/problems/LOWSUM

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
		int k, q;
		cin>>k>>q;

		LL a[k], b[k];
		read(a, k);
		read(b, k);

		sort(a, a+k);
		sort(b, b+k);

		multiset<pair<LL, pair<int, int> > > minheap;
		for(int i=0; i<k; i++)
			minheap.insert({a[i]+b[0], {i, 0}});

		vector<LL> ans;
		while(ans.size()<10001 && !minheap.empty()){
			auto top = *minheap.begin();
			minheap.erase(minheap.begin());
			ans.push_back(top.first);

			int i = top.second.first;
			int j = top.second.second + 1;
			if(j<k)
				minheap.insert({a[i] + b[j], {i, j}});
		}

		while(q--){
			int v;
			cin>>v;
			cout<<ans[v-1]<<endl;
		}
	}

	return 0;
}
