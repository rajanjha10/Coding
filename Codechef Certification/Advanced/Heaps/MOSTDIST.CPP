// https://www.codechef.com/problems/MOSTDIST

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
	int q, cnt = 0;
	LL ans = 0;
	LL x, y, n;
	char op;

	priority_queue<array<LL, 2> > pq1, pq2, pq3, pq4;
	map<int, bool> m;

	cin>>q;
	while(q--){
		cin>>op;
		if(op == '+'){
			cnt++;
			cin>>x>>y;
			x ^= ans;
			y ^= ans;

			pq1.push({x+y, cnt});
			pq2.push({-x+y, cnt});
			pq3.push({x-y, cnt});
			pq4.push({-x-y, cnt});
		}
		else if(op == '-'){
			cin>>n;
			n ^= ans;
			m[n] = 1;
		}
		else{
			cin>>x>>y;
			x ^= ans;
			y ^= ans;

			while(!pq1.empty() && m[pq1.top()[1]])
				pq1.pop();
			while(!pq2.empty() && m[pq2.top()[1]])
				pq2.pop();
			while(!pq3.empty() && m[pq3.top()[1]])
				pq3.pop();
			while(!pq4.empty() && m[pq4.top()[1]])
				pq4.pop();

			LL a = pq1.top()[0];
			LL b = pq2.top()[0];
			LL c = pq3.top()[0];
			LL d = pq4.top()[0];
			ans = max({a-(x+y), b-(-x+y), c-(x-y), d-(-x-y)});
			cout<<ans<<"\n";
		}
	}

	return 0;
}
