// https://acm.timus.ru/problem.aspx?space=1&num=1306

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
	int n;
	unsigned int a;
	cin>>n;
	priority_queue<unsigned int> pq;

	for(int i=0; i<=n/2; i++){
		cin>>a;
		pq.push(a);
	}

	for(int i=0; i<n-n/2-1; i++){
		cin>>a;
		pq.push(a);
		pq.pop();
	}

	cout<<fixed<<setprecision(1);
	if(n&1)
		cout<<pq.top()<<"\n";
	else{
		a = pq.top();
		pq.pop();
		cout<<(a+pq.top())/2.0<<"\n";
	}

	return 0;
}
