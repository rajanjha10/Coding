// https://www.spoj.com/problems/RENT/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

struct Order{
	LL s, e, p;

	Order(){
		s = e = p = 0;
	}

	Order(LL start, LL end, LL price){
		s = start;
		e = end;
		p = price;
	}

	inline pair<pair<LL, LL>, LL> toPair() const {
		return make_pair(make_pair(e, s), p);
	}

	friend bool operator<(const Order &a, const Order &b) {
		return a.toPair() < b.toPair();
	}
};

int bs(Order a[], int index){
	int low = -1, high = index;
	while(high-low>1){
		int mid = low + (high-low)/2;
		if(mid==-1 || a[mid].e < a[index].s)
			low = mid;
		else
			high = mid;
	}

	return low;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		LL s, e, p;
		Order a[n];

		for(int i=0; i<n; i++){
			cin>>s>>e>>p;
			a[i] = Order(s, s+e, p);
		}

		sort(a, a+n);
		
		LL dp[n];
		dp[0] = a[0].p;

		for(int i=1; i<n; i++){
			LL include = a[i].p;

			int index = bs(a, i);
			if(index!=-1)
				include += dp[index];

			LL exclude = dp[i-1];
			dp[i] = max(include, exclude);
		}

		cout<<dp[n-1]<<endl;
	}

	return 0;
}

//top down
LL dp[10010];

LL eval(Order a[], int n){
	if(n<0)
		return 0;

	if(dp[n]!=-1)
		return dp[n];

	LL include = a[n].p;

	int i = bs(a, n);
	if(i!=-1)
		include += eval(a, i);

	LL exclude = eval(a, n-1);
	
	return dp[n] = max(include, exclude);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		LL n;
		cin>>n;
		LL s, e, p;
		Order a[n];
			
		for(int i=0; i<n; i++){
			cin>>s>>e>>p;
			a[i] = Order(s, s+e, p);
		}

		sort(a, a+n);
		memset(dp, -1, sizeof(dp));

		cout<<eval(a, n-1)<<endl;

	}

	return 0;
}
