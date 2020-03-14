//https://www.codechef.com/JULY17/problems/IPCTRAIN

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool cmp(const vector<int>&v1, const vector<int>&v2){
	return v1[0]<v2[0];
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, d;
		cin>>n>>d;
		vector<vector<int> > a(n, vector<int>(3));
		priority_queue<pair<int, int>> pq;
		for(int i=0; i<n; i++)
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		
		sort(a.begin(), a.end(), cmp);

		int j=0;
		for(int i=1; i<=d; i++){
			while(j<n && a[j][0]==i){
				pq.push({a[j][2], a[j][1]});
				j++;
			}
			if(!pq.empty()){
				pair<int, int> v = pq.top();
				pq.pop();
				if(v.second>1){
					v.second = v.second-1;
					pq.push(v);
				}
			}
		}

		LL ans=0;
		while(!pq.empty()){
			ans += pq.top().first * pq.top().second;
			pq.pop();
		}

		cout<<ans<<endl;
	}

	return 0;
}
