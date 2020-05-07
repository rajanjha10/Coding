// https://www.spoj.com/problems/SCALE/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

vector<LL> sums;
vector<int> ansl, ansr;

bool eval(LL x, LL s, LL n){
	vector<int> tkpx(n, 0), tk(n, 0);
	LL kpx = s, k = s-x;

	int i=0;
	while(kpx>0){
		if(kpx%3==2)
			return false;
		tkpx[i++] = kpx % 3;
		kpx /= 3;
	}
	
	i=0;
	while(k>0){
		if(k%3==2)
			return false;
		tk[i++] = k % 3;
		k /= 3;
	}

	for(int i=0; i<n; i++)
		if(tkpx[i] && tk[i])
			return false;

	ansl = tk;
	ansr = tkpx;

	return true;
}

int main()
{
	fastio;
	int n;
	LL x;
	cin>>n>>x;

	LL pweight[n];
	
	LL mul = 1;
	for(int i=0; i<n; i++){
		pweight[i] = mul;
		mul *= 3;
	}
	
	for(int i=0; i<n; i++){
		LL sz = sums.size(); 
		for(LL j=0; j<sz; j++)
			sums.push_back(pweight[i] + sums[j]);
		
		sums.push_back(pweight[i]);
	}	

	sort(sums.begin(), sums.end());

	LL valIndex = lower_bound(sums.begin(), sums.end(), x) - sums.begin();
	if(valIndex == sums.size()){
		cout<<-1<<endl;
		return 0;
	}

	for(LL i=valIndex; i<sums.size(); i++){
		if(eval(x, sums[i], n))
			break;
	}

	if(ansl.empty())
		cout<<-1<<endl;
	else{
		for(int i=0; i<ansl.size(); i++){
			if(ansl[i])
				cout<<i+1<<" ";
		}

		cout<<endl;

		for(int i=0; i<ansr.size(); i++){
			if(ansr[i])
				cout<<i+1<<" ";
		}
	}

	return 0;
}
