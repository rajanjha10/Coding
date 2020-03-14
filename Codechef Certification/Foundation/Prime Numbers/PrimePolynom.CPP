//https://community.topcoder.com/stat?c=problem_statement&pm=4475&rd=8012

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

class PrimePolynom{
private:
	bool check_prime(int a){
		if(a<2) 
			return false;
		for(int i=2; i*i<=a; i++){
			if(a%i==0)
				return false;
		}

		return true;
	}

public:
	int reveal(int A, int B, int C){
		for(int m=0; true; m++){
			if(!(check_prime(A*m*m + B*m + C)))
				return m;
		}
	}
};
