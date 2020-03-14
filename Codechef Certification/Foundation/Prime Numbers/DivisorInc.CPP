//https://community.topcoder.com/stat?c=problem_statement&pm=6186&rd=9823

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

class DivisorInc{
public:
	int countOperations(int N, int M){
		int dist[M+1];
		memset(dist, -1, sizeof(dist));
		dist[N]=0;
		queue<int> q;
		q.push(N);

		while(!q.empty()){
			int x = q.front();
			q.pop();

			if(x==M) break;

			for(auto i: get_divisors(x)){
				if(x+i<=M && dist[x+i]==-1){
					q.push(x+i);
					dist[x+i] = dist[x] + 1;  
				}
			}
		}

		return dist[M];
	}

private:
	vector<int> get_divisors(int x){
		vector<int> divisors;
		for(int i=2; i*i<=x; i++){
			if(x%i==0){
				divisors.push_back(i);
				divisors.push_back(x/i);
			}
		}

		return divisors;
	}
};