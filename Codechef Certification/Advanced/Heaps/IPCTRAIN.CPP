// https://www.codechef.com/problems/IPCTRAIN

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
		int n, d;
		cin>>n>>d;
		array<int, 3> a[n];
		for(int i=0; i<n; i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];

		sort(a, a+n, [&](const array<int, 3>& a, const array<int, 3>& b){
			return a[0]<b[0];
		});

		priority_queue<pair<int, int> > pq;
		for(int i=1, j=0; i<=d; i++){
			while(j<n && a[j][0]==i){
				pq.push({a[j][2], a[j][1]});
				j++;
			}

			if(!pq.empty()){
				auto p = pq.top();
				pq.pop();
				if(p.second>1){
					p.second-=1;
					pq.push(p);
				}
			}
		}

		LL ans = 0;
		while(!pq.empty()){
			ans += (LL)pq.top().first * pq.top().second;
			pq.pop();
		}

		cout<<ans<<"\n";

	}

	return 0;
}
