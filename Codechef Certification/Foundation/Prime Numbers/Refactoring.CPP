//https://community.topcoder.com/stat?c=problem_statement&pm=2986&rd=5862

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

class Refactoring{
private:
	int count(int n, int lastFactor){
		int result = 0;
		for(int i=lastFactor; i*i<=n; i++){
			if(n%i==0)
				result += count(n/i, i) + 1;
		}
		return result;
	}

public:
	int refactor(int n){
		return count(n, 2);
	}
};
