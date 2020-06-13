// https://www.spoj.com/problems/RMID2/

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
		LL sz = 0;
		priority_queue<LL, vector<LL>, greater<LL> > minheap;
		priority_queue<LL> maxheap;
		while(1){
			LL n;
			cin>>n;
			
			if(n==0)
				break;

			if(n==-1 && !maxheap.empty()){
				cout<<maxheap.top()<<"\n";
				maxheap.pop();
				sz--;
			}
			else{
				sz++;
				if(!maxheap.empty() && n<maxheap.top()){
					minheap.push(maxheap.top());
					maxheap.pop();
					maxheap.push(n);
				}
				else
					minheap.push(n);
			}

			if(sz&1){
				maxheap.push(minheap.top());
				minheap.pop();
			}
		}
	}

	return 0;
}
