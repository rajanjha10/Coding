//https://www.codechef.com/problems/STACKS

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
		LL a[n];
		read(a, n);

		multiset<LL> stack;
		for(int i=0; i<n; i++){
			auto it = stack.upper_bound(a[i]); 
			if(it==stack.end())
				stack.insert(a[i]);
			else{
				stack.erase(it);
				stack.insert(a[i]);
			}
		}

		cout<<stack.size()<<" ";
		for(auto i: stack)
			cout<<i<<" ";
		cout<<endl;
	}

	return 0;
}
