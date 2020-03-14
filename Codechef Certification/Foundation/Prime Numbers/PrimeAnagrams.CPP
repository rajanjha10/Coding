//https://community.topcoder.com/stat?c=problem_statement&pm=3458&rd=5869

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

class PrimeAnagrams{
	
private:
	bool isPrime(int x){
		if(x<2) 
			return false;
		for(int i=2; i*i<=x; i++){
			if(x%i==0)
				return false;
		}

		return true;
	}

public:
	vector<int> primes(string anagram){
		sort(anagram.begin(), anagram.end());
		vector<int> ans(3);
		LL minProduct = 1LL<<60;

		do{
			for(int i=0; i<anagram.size()-2; i++){
				for(int j=i+1; j<anagram.size()-1; j++){
					string sa = anagram.substr(0, i+1);
					string sb = anagram.substr(i+1, j);
					string sc = anagram.substr(j+1);
					
					if(sa[0]=='0' || sb[0]=='0' || sc[0]=='0')
						continue;

					int a = atoi(sa.c_str());
					int b = atoi(sb.c_str());
					int c = atoi(sc.c_str());
					
					if(isPrime(a) && isPrime(b) && isPrime(c) && (LL)a*b*c<minProduct){
						minProduct = (LL)a*b*c;
						ans[0] = a;
						ans[1] = b;
						ans[2] = c;
					}
				}
			}
			
		}while(next_permutation(anagram.begin(), anagram.end()));
		
		sort(ans.begin(), ans.end());
		if(minProduct<(1LL<<60))
			return ans;
		return {};
	}
};
