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
	LL n, x, sz=0;
	cin>>n;
	priority_queue<LL> max;
	priority_queue<LL, vector<LL>, greater<LL> > min;

	while(n--){
		int op;
		cin>>op;
		if(op==1){
			cin>>x;
			sz++;
			max.push(x);
		}
		else if(op==2){
			if(sz<3)
				cout<<"No reviews yet"<<"\n";
			else
				cout<<min.top()<<"\n";
		}

		while(min.size()<sz/3){
			min.push(max.top());
			max.pop();
		}

		while(!max.empty() && !min.empty() && max.top()>min.top()){
			LL y = min.top();
			min.pop();
			min.push(max.top());
			max.pop();
			max.push(y);
		}	
	}

	return 0;
}
