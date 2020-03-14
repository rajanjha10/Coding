//https://www.codechef.com/problems/TSECJ05

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
		LL k, n, a;
		cin>>k>>n;
		multiset<LL> minHeap;

		while(n--){
			cin>>a;
			minHeap.insert(a);
			if(minHeap.size()>k)
				minHeap.erase(minHeap.begin());
			
			if(minHeap.size()<k)
				cout<<-1<<" ";
			else
				cout<<*minHeap.begin()<<" ";
		}
		cout<<endl;
	}

	return 0;
}
