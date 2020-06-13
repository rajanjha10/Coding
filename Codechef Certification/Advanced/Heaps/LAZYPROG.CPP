// https://www.spoj.com/problems/LAZYPROG/

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
		array<LL, 3> a[n];

		for(int i=0; i<n; i++)
			for(int j=0; j<3; j++)
				cin>>a[i][j];

		sort(a, a+n, [&](const array<LL, 3>& u, const array<LL, 3>& v){
			return u[2]<v[2];
		});

		priority_queue<pair<int, int> > pq;
		LL time = 0;
		double money = 0;
		for(int i=0; i<n; i++){
			time += a[i][1];
			pq.push({a[i][0], a[i][1]});

			if(time <= a[i][2])
				continue;

			while(1){
				auto tp = pq.top();
				pq.pop();

				if(time - tp.second <= a[i][2]){
					tp.second -= time - a[i][2];
					money += (time - a[i][2])/(double)tp.first;
					time = a[i][2];
					pq.push(tp);
					break;
				}
				else{
					money += (double)tp.second/tp.first;
					time -= tp.second;
				}
			}
		}
		
		cout<<fixed<<setprecision(2)<<money<<"\n";
	}

	return 0;
}
