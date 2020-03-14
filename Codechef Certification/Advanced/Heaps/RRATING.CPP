//https://www.codechef.com/problems/RRATING

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
	LL n, op, x, sz=0;
	cin>>n;
	multiset<LL, greater<LL> > maxHeap;
	multiset<LL> minHeap;
	
	while(n--){
		cin>>op;
		if(op==1){
			cin>>x;
			sz++;
			
			if(!minHeap.empty() && x>*minHeap.begin()){
			    maxHeap.insert(*minHeap.begin());
			    minHeap.erase(minHeap.begin());
				minHeap.insert(x);
			}
			else
			    maxHeap.insert(x);
			
			while(minHeap.size()<floor(sz/3)){
				minHeap.insert(*maxHeap.begin());
				maxHeap.erase(maxHeap.begin());
			}
		}
		else{
			if(minHeap.empty())
				cout<<"No reviews yet"<<endl;
			else
				cout<<*minHeap.begin()<<endl;
		}
	}

	return 0;
}
