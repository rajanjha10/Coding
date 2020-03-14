//https://www.spoj.com/problems/WEIRDFN/

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
		LL a, b, c, n, sum=0;
		priority_queue<LL, vector<LL>, greater<LL> > minHeap;
		priority_queue<LL> maxheap;
		cin>>a>>b>>c>>n;

		a=a%MOD;
		b=b%MOD;
		c=c%MOD;
		
		minHeap.push(1);
		sum += 1;
		for(LL i=2; i<=n; i++){
			if((i-1)&1){
				maxheap.push(minHeap.top());
				minHeap.pop();
			}

			LL m = maxheap.top();
			LL f = ((a*m)%MOD + (b*i)%MOD + c)%MOD;
			sum += f;
			
			if(f<maxheap.top()){
				minHeap.push(maxheap.top());
				maxheap.pop();
				maxheap.push(f);
			}
			else
				minHeap.push(f);
		}

		cout<<sum<<endl;
	}

	return 0;
}
