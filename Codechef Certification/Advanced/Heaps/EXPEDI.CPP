// https://www.spoj.com/problems/EXPEDI/

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
		LL n, l, p;
		cin>>n;

		array<LL, 2> a[n];
		for(int i=0; i<n; i++)
			cin>>a[i][0]>>a[i][1];

		cin>>l>>p;
		for(int i=0; i<n; i++)
			a[i][0] = l - a[i][0];

		sort(a, a+n, [&](const array<LL, 2>& u, const array<LL, 2>& v){
			return u[0]<v[0];
		});

		priority_queue<LL> pq;
		LL ans = 0, index = 0;
		for(int i=0; i<l; i++, p--){
			if(index<n && a[index][0]==i){
				pq.push(a[index][1]);
				index++;
			}

			if(p==0){
				if(pq.empty()){
					ans = -1;
					break;
				}

				p += pq.top();
				pq.pop();
				ans++;
			}
		}

		cout<<ans<<"\n";
	}

	return 0;
}
